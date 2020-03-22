set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CPU_ARCH cortex-m4)
set(FPU_ARCH fpv4-sp-d16)
set(FLOAT_ABI soft)
set(CMAKE_SPECS nano.specs)
set(LINKER_SCRIPT "-Tlibs.ld -Tmem.ld -Tsections.ld -L${CMAKE_CURRENT_SOURCE_DIR}/ldscripts")

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

set(BUILD_FLAGS "\
    -nostartfiles \
    --specs=${CMAKE_SPECS} \
    ${LINKER_SCRIPT} \
    -mcpu=${CPU_ARCH} \
    -mfloat-abi=${FLOAT_ABI} \
    -mthumb \
    -Og \
    -fmessage-length=0 \
    -fsigned-char \
    -ffunction-sections \
    -fdata-sections \
    -fno-move-loop-invariants \
    -Wall \
    -Wextra \
    -g3 \
    "
)
set(CMAKE_C_FLAGS ${BUILD_FLAGS})
set(CMAKE_CXX_FLAGS ${BUILD_FLAGS})