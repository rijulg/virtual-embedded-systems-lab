# Lab 1 - Introduction
In this lab we will be setting up the system needed to run these labs and then going through GPIO operations of STM32F4-Discovery boards.

## Part 1 - Setup (20%)
If you haven't already done so, follow the [README.md](../../README.md) in the root of this project and follow the setup instructions. Once you have finished setup you must be able to get all the LEDs blinking. This step is crucial for this and all the rest of the labs to work as without getting this step to work you won't be able to work on any of the labs.

## Part 2 - GPIO (40%)
In this part you have to blink the Green LED. Use the file `part2.c` to write your code and then run it by selecting `Lab_1_Part_2` in the **Run Lab** task.

## Part 3 - Morse Code (40%)
Building up on the previous implementation now we need to blink the Green LED in a certain order so as to transmit morse code. Use the file `part3.c` to write your code and then run it by selecting `Lab_1_Part_3` in the **Run Lab** task..

### Hints
* Read `stm32f4xx_hal_gpio.h`