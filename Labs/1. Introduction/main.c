#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include <stdlib.h>
#include <stdio.h>

const uint16_t LEDS = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
const uint16_t LED[4] = {GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15};

void delay(uint32_t ms) {
    ms *= 3360;
    while(ms--) {
        __NOP();
    }
}

int main(void)
{
    printf("I am starting\n");
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Pin = LEDS;
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(GPIOD, &gpio);
    GPIO_SetBits(GPIOD, LEDS);
    static uint32_t counter = 0;
    
    while(1) { 
        counter++;
        // GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
        GPIO_ResetBits(GPIOD, LEDS);
        GPIO_SetBits(GPIOD, LED[counter % 4]);
        delay(250);
    }

    return 1;
}