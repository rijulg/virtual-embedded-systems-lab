cmake_minimum_required(VERSION 3.0)

project(labs)

include(toolchain.cmake)

add_subdirectory(stm32f4xx)

add_executable(lab1.elf "../Labs/1. Introduction/main.c")
target_link_libraries(lab1.elf stm32f4xx)