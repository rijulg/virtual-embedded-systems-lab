#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

static char *MORSE_CODE_TABLE[] = {
    ".-", "-...", "-.-.", "-..",
    ".", "..-.", "--.", "....",
    "..", ".---", ".-.-", ".-..",
    "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

/**
 * @todo Implement
 * You need to do the following to set the green led pin as output
 *  1. Enable GPIOx clock first.
 *  2. Initialize the GPIOx port with the specified pins as output
 * You can get this information either from looking at examples.
 * Try to look for examples of STM32F407xx GPIO initialisation online.
*/
static void _led_pinmode_out() {
}

/**
 * @todo Implement
 * Here you need to output a given string (char array) in morse code.
 * To achieve this you need to do the following:
 *  1. Convert each character of the string into it's morse code equivalent
 *  2. Blink the LED based on whether a dot or dash needs to be transmitted.
 *    2.1. A dot may be  LED ON -> DELAY 100 -> LED OFF -> DELAY 100
 *    2.2. A dash may be LED ON -> DELAY 500 -> LED OFF -> DELAY 500
 */
static void _transmitMorseCode(const char *input) {
}

int main() {
  _led_pinmode_out();
  while(1) { _transmitMorseCode("HELLO"); }
  return 1;
}
