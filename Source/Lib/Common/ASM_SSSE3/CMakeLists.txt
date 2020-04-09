#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# ASM_SSSE3 Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX512/)

set(flags_to_test -mssse3)

if(CMAKE_C_COMPILER_ID STREQUAL "Intel" AND NOT WIN32)
    list(APPEND flags_to_test -static-intel -w)
endif()

test_apply_compiler_flags(${flags_to_test})

set(all_files
    aom_subpixel_bilinear_ssse3.asm
    av1_inv_txfm_ssse3.c
    av1_inv_txfm_ssse3.h
    EbAvcStyleMcp_Intrinsic_SSSE3.c
    EbAvcStyleMcp_SSSE3.h
    EbHighbdIntraPrediction_Intrinsic_SSSE3.c
    intrapred_ssse3.c
    reconinter_ssse3.c
    )

#list(REMOVE_ITEM all_files ${asm_includes})

add_library(COMMON_ASM_SSSE3 OBJECT ${all_files})
