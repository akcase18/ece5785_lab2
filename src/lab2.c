#include <stdbool.h>
#include "pico/cyw43_arch.h"
#include "lab2.h"

bool switch_led_state(bool led_state, int counter)
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_state); // Set state of on-board LED to state of led_is_on
    if (counter % 47)                                    // Check if counter is not an even multiple of 47
    {
        led_state = !led_state; // Swtich the state of the on-board LED
    }
    return led_state;
}

char switch_capitalization(char c)
{
    if (c <= 'z' && c >= 'a')      // Check if c is a lowercase letter
        return c - 32;           // Return character, but uppercase
    else if (c >= 'A' && c <= 'Z') // Check if c is an uppercase letter
        return c + 32;           // Return character, but lowercase
    else
        return c; // Return character
}