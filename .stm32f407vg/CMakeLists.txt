cmake_minimum_required(VERSION 3.0)

project(labs)

include(toolchain.cmake)

file(GLOB_RECURSE SYSTEM_SRCS
    ${PROJECT_SOURCE_DIR}/stm32f4xx/src/*.c
    ${PROJECT_SOURCE_DIR}/stm32f4xx/src/*.cpp
)

add_executable(lab.elf ${SYSTEM_SRCS} ${SOURCE_FILE})
target_include_directories(lab.elf
    PRIVATE
        ${PROJECT_SOURCE_DIR}/stm32f4xx/inc
        ${PROJECT_SOURCE_DIR}/stm32f4xx/inc/cmsis
        ${PROJECT_SOURCE_DIR}/stm32f4xx/inc/stm32f4-hal
)
target_compile_definitions(lab.elf
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
