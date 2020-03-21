set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CPU_ARCH cortex-m4)
set(FPU_ARCH fpv4-sp-d16)
set(FLOAT_ABI softfp)
set(CMAKE_SPECS nosys.specs)
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/stm32f4xx/src/stm32f407vg.ld)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
# Avoid known bug in linux giving: 
# arm-none-eabi-gcc: error: unrecognized command line option '-rdynamic'
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_FLAGS "-mcpu=${CPU_ARCH} -mfpu=${FPU_ARCH} -mfloat-abi=${FLOAT_ABI} --specs=${CMAKE_SPECS} -T${LINKER_SCRIPT} -Wl,--gc-sections -fmessage-length=0 -ffunction-sections -fdata-sections -ffreestanding")