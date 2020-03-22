cmake_minimum_required(VERSION 3.0)

project(labs)

include(toolchain.cmake)

set(SOURCES
    ## C Files With Checks
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_cortex.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_dfsdm.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_flash.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_flash_ex.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_gpio.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_iwdg.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_pwr.c
    ${PROJECT_SOURCE_DIR}/system/src/stm32f4-hal/stm32f4xx_hal_rcc.c
    ## C Files Without Checks
    ${PROJECT_SOURCE_DIR}/system/src/newlib/_exit.c
    ${PROJECT_SOURCE_DIR}/system/src/newlib/_sbrk.c
    ${PROJECT_SOURCE_DIR}/system/src/newlib/_syscalls.c
    ${PROJECT_SOURCE_DIR}/system/src/newlib/assert.c
    ${PROJECT_SOURCE_DIR}/system/src/diag/Trace.c
    ${PROJECT_SOURCE_DIR}/system/src/diag/trace_impl.c
    ${PROJECT_SOURCE_DIR}/system/src/cortexm/_initialize_hardware.c
    ${PROJECT_SOURCE_DIR}/system/src/cortexm/_reset_hardware.c
    ${PROJECT_SOURCE_DIR}/system/src/cortexm/exception_handlers.c
    ${PROJECT_SOURCE_DIR}/system/src/cmsis/system_stm32f4xx.c
    ${PROJECT_SOURCE_DIR}/system/src/cmsis/vectors_stm32f407xx.c
    ## CPP Files
    ${PROJECT_SOURCE_DIR}/system/src/newlib/_cxx.cpp
    ## Startup Files
    ${PROJECT_SOURCE_DIR}/system/src/newlib/_startup.c
    ${PROJECT_SOURCE_DIR}/system/src/_initialize_hardware.c
)

list(APPEND SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.c
)

add_executable(blinky.elf ${SOURCES})
target_include_directories(blinky.elf
    PRIVATE
        # ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/system/include
        ${PROJECT_SOURCE_DIR}/system/include/cmsis
        ${PROJECT_SOURCE_DIR}/system/include/stm32f4-hal
)
target_compile_definitions(blinky.elf
    PRIVATE
        -DDEBUG
        -DUSE_FULL_ASSERT
        -DOS_USE_SEMIHOSTING
        -DTRACE
        -DOS_USE_TRACE_SEMIHOSTING_DEBUG
        -DSTM32F407xx
        -DUSE_HAL_DRIVER
        -DHSE_VALUE=8000000
        -DOS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS
)
