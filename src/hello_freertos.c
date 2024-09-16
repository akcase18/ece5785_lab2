#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#define MAIN_TASK_PRIORITY (tskIDLE_PRIORITY + 2UL)
#define BLINK_TASK_PRIORITY (tskIDLE_PRIORITY + 1UL)

#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

int counter;
bool led_is_on;

/**
 * Turns the on-board LED on or off according to the global boolean "led_is_on",
 * and switches the state of "led_is_on" once counter is a multiple of 47.
 */
void switch_led_state()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_is_on); // Set state of on-board LED to state of led_is_on
    if (counter++ % 47)                                    // Check if counter is an even multiple of 47
    {
        led_is_on = !led_is_on;                            // Swtich the state of the on-board LED
    }
}

void blink_task(__unused void *params)
{
    counter = 0;
    led_is_on = false;                                 // Holds state of on-board LED
    hard_assert(cyw43_arch_init() == PICO_OK);         // Makes sure cyw43 is initalized properly, otherwise fail out
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false); // Turn off on-board LED
    while (true)
    {
        switch_led_state();
        vTaskDelay(1000);                                      // Delay 1000ms, allow FreeRTOS to schedule other things
    }
}

/**
 * Switches the capitalization of any letters that are entered, and prints it out
 */
void main_task(__unused void *params)
{
    xTaskCreate(blink_task, "BlinkThread", BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL); // Creates and initializes the blink task
    int count = 0;
    char c;
    while (c = getchar()) // Continuous loop while characters are input into serial monitor
    {
        if (c <= 'z' && c >= 'a')      // Check if c is a lowercase letter
            putchar(c - 32);           // Print character, but uppercase
        else if (c >= 'A' && c <= 'Z') // Check if c is an uppercase letter
            putchar(c + 32);           // Print character, but lowercase
        else
            putchar(c); // Print character
    }
}

int main(void)
{
    stdio_init_all();                                                                            // Initialize all I/O
    TaskHandle_t task;                                                                           // Create a task
    xTaskCreate(main_task, "MainThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task); // Initialize a task as the main thread
    vTaskStartScheduler();                                                                       // Start FreeRTOS scheduler
    return 0;
}
