#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

static void _init_button() {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef gpio;
  // Configure pin in output push/pull mode
  gpio.Pin = GPIO_PIN_0;
  gpio.Mode = GPIO_MODE_IT_RISING;
  gpio.Speed = GPIO_SPEED_LOW;
  gpio.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOA, &gpio);
  NVIC_EnableIRQ(EXTI0_IRQn);
}

/** Default external line 1 handler */
void EXTI0_IRQHandler(void) { HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0); }

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    }
}

void setup() {
  __HAL_RCC_GPIOD_CLK_ENABLE();
  GPIO_InitTypeDef gpio;
  gpio.Pin = GPIO_PIN_12;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Speed = GPIO_SPEED_FAST;
  gpio.Pull = GPIO_PULLUP;
  HAL_GPIO_Init (GPIOD, &gpio);
  _init_button();
}

void loop() {
  HAL_Delay(750);
}

int main() {
  setup();
  while(1) { loop(); }
  return 1;
}
