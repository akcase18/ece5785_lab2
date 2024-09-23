#ifndef LAB2_H
#define LAB2_H

/**
 * Turns the on-board LED on or off according to the global boolean "led_state",
 * and switches the state of "led_state" once counter is not a multiple of 47.
 * Essentially what is happening is the LED will switch state a bunch of times, 
 * until counter is 
 * 
 * @param led_state bool to hold the state of the on-board LED
 * @param counter the counter that is incrementing up
 * @return the new state of the on-board LED
 */
bool switch_led_state(bool led_state, int counter);

/**
 * Takes the given character and checks whether it is a lowercase letter,
 * uppercase letter, or non-letter character. If it is a lowercase letter,
 * it returns the same letter, but uppercase. If it is an uppercase
 * letter, it returns the same letter, but lowercase. If it is not a
 * letter, then it returns the character but unchanged.
 * 
 * @param c input character
 * @return output character that has been modified
 */
char switch_capitalization(char c);

#endif