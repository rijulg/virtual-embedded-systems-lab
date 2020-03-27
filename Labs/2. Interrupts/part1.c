#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

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
 * This is similar to _led_pinmode_out
 */
static void _button_pinmode_input() {
}

static void _setup() {
  _led_pinmode_out();
  _button_pinmode_input();
}

/**
 * @todo Implement
 * You need to listen for the user button press and if the button is pressed then turn the LED ON
 * NOTE: button pressed and button released are 2 different things!
 */
static void _loop() {
}

int main() {
  _setup();
  while(1) { _loop(); }
  return 1;
}
