# Lab 4 SPI Based Driver
In this lab we are assuming that you have a working SPI, it does not matter if it's bit-banged or hardware and that is the beauty of abstraction. Now using the interface provided by the SPI's implementation (spi.h) we will be implementing a driver for a digital temperature sensor. The temperature sensor we will be working with is ADT7320 and it's datasheet has been provided in the folder.

The source file `adt7320.c` has functions that call `verify_xx` functions, these are helper functions designed so that you can verify that your code works. The other file that is included while building this lab `spi.o` has the implementation of all the functions declared in `spi.h` and the file is emulating the temperature sensor. The emulation is only implemented so much that this lab can be completed and you will not be able to execute any other functionality than that required by the lab.

### How to write your own emulator
Essentially we are following testing methodologies here and dropping in a mock implementation. Here the code we write has a dependency on a spi driver, as such we can intercept all calls made to the spi and send back responses as we wish from the mock. Mocking and Fakes are an integral part of testing, and there are a lot of resources out there for high level languages. Unfortunately good resources on testing embedded system devices and firmware are scarce, if you would like to (and you should!) learn more about how to do TDD (Test Driven Development) by going through [Test Driven Development for Embedded C by James Grenning](https://www.oreilly.com/library/view/test-driven-development/9781941222997/).

### A note on testing
If you find yourself leading any software team, you would find tests as one of the best investment of your time. Even though testing has plenty of benefits for software development in all fields of software, it has far more benefits in embedded systems. By having a good suite of tests you can not only verify that your firmware is implemented correctly, but also use it to figure out if your hardware is configured correctly, you can supply the tests to factories that build your devices so that each device can be tested before it leaves the factory floor etc.

## Part 1 - Reading IDs (10%)
The first part of this lab is to identify the manufacturer and revision id of the device. This part has been made separate so that you have an easy task to get yourself familiarised with the datasheet.

## Part 2 - Reading temperature (90%)
To read the temperature you need to configure the device correctly, make sure that the readings are ready for you to read, read the readings and then convert them using formulas given in the datasheet.

### Hints
* Make sure you are reading Bit(s) and Values for registers in the write orderr
* Make sure you have checked that temperature reading is ready for you to read before you read it
* You might have to do an operation after reading the temperature
