cmake_minimum_required(VERSION 3.0)

project(labs)

include(toolchain.cmake)

# file(GLOB LIB_CPP_FILES ${PROJECT_SOURCE_DIR}/system/src/**/*.cpp)
# file(GLOB LIB_C_FILES ${PROJECT_SOURCE_DIR}/system/src/**/*.c)
# add_library(stm32f4 ${LIB_C_FILES} ${LIB_CPP_FILES})
# target_include_directories(stm32f4
#     PUBLIC
#         ${PROJECT_SOURCE_DIR}/system/include
#         ${PROJECT_SOURCE_DIR}/system/include/cmsis
#         ${PROJECT_SOURCE_DIR}/system/include/stm32f4-hal
#         ${PROJECT_SOURCE_DIR}/include
# )


# add_executable(blinky.elf
#     ${PROJECT_SOURCE_DIR}/src/main.cpp
#     ${PROJECT_SOURCE_DIR}/src/BlinkLed.cpp
#     ${PROJECT_SOURCE_DIR}/src/Timer.cpp
#     # ??
#     ${PROJECT_SOURCE_DIR}/src/_initialize_hardware.c
#     ${PROJECT_SOURCE_DIR}/src/_write.c
#     ${PROJECT_SOURCE_DIR}/src/stm32f4xx_hal_msp.c
#     # ????
#     ${PROJECT_SOURCE_DIR}/system/src/newlib/_startup.c
# )
# target_include_directories(blinky.elf PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_link_libraries(blinky.elf PRIVATE stm32f4)

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
)

list(APPEND SOURCES
    ${PROJECT_SOURCE_DIR}/src/BlinkLed.cpp
    ${PROJECT_SOURCE_DIR}/src/Timer.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/_initialize_hardware.c
    ${PROJECT_SOURCE_DIR}/src/_write.c
    ${PROJECT_SOURCE_DIR}/src/stm32f4xx_hal_msp.c
)

add_executable(blinky.elf ${SOURCES})
target_include_directories(blinky.elf
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/system/include
        ${PROJECT_SOURCE_DIR}/system/include/cmsis
        ${PROJECT_SOURCE_DIR}/system/include/stm32f4-hal
)
