#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

void setup() {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  GPIO_InitTypeDef gpio;
  // Configure pin in output push/pull mode
  gpio.Pin = 1 << 12;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Speed = GPIO_SPEED_FAST;
  gpio.Pull = GPIO_PULLUP;
  HAL_GPIO_Init (GPIOD, &gpio);
}

void loop() {
    GPIOD->BSRR = 1 << (12 + 16);
    HAL_Delay(750);
    GPIOD->BSRR = 1 << (12);
    HAL_Delay(750);
}

int main() {
  setup();
  while(1) { loop(); }
  return 0;
}
