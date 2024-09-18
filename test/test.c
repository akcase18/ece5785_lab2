#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "lab2.h"

void setUp(void) {}

void tearDown(void) {}

void test_upper_to_lower()
{
    char lowercase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int i = 0; i < 26; i++)
    {
        char input = uppercase[i];
        char expected = lowercase[i];
        char output = switch_capitalization(uppercase[i]);
        // TEST_ASSERT_TRUE_MESSAGE(output == expected, "Conversion from " + input + " to " + expected + " failed.");
        TEST_ASSERT_TRUE(output == expected);
    }
}

void test_lower_to_upper()
{
    char lowercase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int i = 0; i < 26; i++)
    {
        char input = lowercase[i];
        char expected = uppercase[i];
        char output = switch_capitalization(lowercase[i]);
        // TEST_ASSERT_TRUE_MESSAGE(output == expected, "Conversion from " + input + " to " + expected + " failed.");
        TEST_ASSERT_TRUE(output == expected);
    }
}

void test_not_a_letter()
{
    char output = switch_capitalization('5');
    TEST_ASSERT_TRUE_MESSAGE(output == '5', "Input was modified. Test failed.");
    output = switch_capitalization('/');
    TEST_ASSERT_TRUE_MESSAGE(output == '/', "Input was modified. Test failed.");
    output = switch_capitalization('+');
    TEST_ASSERT_TRUE_MESSAGE(output == '+', "Input was modified. Test failed.");
}

void test_toggle_led()
{
    /* State shouldn't change */
    int counter = 0;
    bool led_state = false;
    bool output_state = switch_led_state(led_state, counter);
    TEST_ASSERT_FALSE_MESSAGE(output_state == true, "Switched when it wasn't supposed to (False --> True), counter = 0");
    led_state = true;
    output_state = switch_led_state(led_state, counter);
    TEST_ASSERT_FALSE_MESSAGE(output_state == false, "Switched when it wasn't supposed to (True --> False), counter = 0");
    /* State should change */
    counter = 1;
    led_state = false;
    output_state = switch_led_state(led_state, counter);
    TEST_ASSERT_TRUE_MESSAGE(output_state == true, "Failed on False --> True, counter = 1");
    led_state = true;
    output_state = switch_led_state(led_state, counter);
    TEST_ASSERT_TRUE_MESSAGE(output_state == false, "Failed on True --> False, counter = 1");
    /* State should change */
    counter = 26;
    led_state = false;
    TEST_ASSERT_TRUE_MESSAGE(switch_led_state(led_state, counter) == true, "Failed on False --> True, counter = 26");
    led_state = true;
    TEST_ASSERT_TRUE_MESSAGE(switch_led_state(led_state, counter) == false, "Failed on True --> False, counter = 26");
    /* State shouldn't change */
    counter = 47;
    led_state = false;
    TEST_ASSERT_FALSE_MESSAGE(switch_led_state(led_state, counter) == true, "Switched when it wasn't supposed to (False --> True), counter = 47");
    led_state = true;
    TEST_ASSERT_FALSE_MESSAGE(switch_led_state(led_state, counter) == false, "Switched when it wasn't supposed to (True --> False), counter = 47");
    /* State should change */
    counter = 83;
    led_state = false;
    TEST_ASSERT_TRUE_MESSAGE(switch_led_state(led_state, counter) == true, "Failed on False --> True, counter = 83");
    led_state = true;
    TEST_ASSERT_TRUE_MESSAGE(switch_led_state(led_state, counter) == false, "Failed on True --> False, counter = 83");
    /* State shouldn't change */
    counter = 141;
    led_state = false;
    TEST_ASSERT_FALSE_MESSAGE(switch_led_state(led_state, counter) == true, "Switched when it wasn't supposed to (False --> True), counter = 141");
    led_state = true;
    TEST_ASSERT_FALSE_MESSAGE(switch_led_state(led_state, counter) == false, "Switched when it wasn't supposed to (True --> False), counter = 141");
}

int main (void)
{
    stdio_init_all();
    UNITY_BEGIN();
    RUN_TEST(test_upper_to_lower);
    RUN_TEST(test_lower_to_upper);
    RUN_TEST(test_not_a_letter);
    RUN_TEST(test_toggle_led);
    return UNITY_END();
}