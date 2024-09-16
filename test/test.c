#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "lab2.h"

void setUp(void)
{

}

void tearDown(void)
{

}

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

void test_non_numeric()
{
    char output = switch_capitalization('5');
    TEST_ASSERT_TRUE_MESSAGE(output == '5', "Input was modified. Test failed.");
    output = switch_capitalization('/');
    TEST_ASSERT_TRUE_MESSAGE(output == '/', "Input was modified. Test failed.");
    output = switch_capitalization('+');
    TEST_ASSERT_TRUE_MESSAGE(output == '+', "Input was modified. Test failed.");
}

int main (void)
{
    stdio_init_all();
    UNITY_BEGIN();
    RUN_TEST(test_upper_to_lower);
    RUN_TEST(test_lower_to_upper);
    RUN_TEST(test_non_numeric);
    return UNITY_END();
}