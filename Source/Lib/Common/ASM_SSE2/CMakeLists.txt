#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# ASM_SSE2 Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/)

set(flags_to_test -msse2)

if(CMAKE_C_COMPILER_ID STREQUAL "Intel" AND NOT WIN32)
    list(APPEND flags_to_test -static-intel -w)
endif()

test_apply_compiler_flags(${flags_to_test})

set(all_files
    aom_subpixel_8t_sse2.asm
    av1_txfm_sse2.h
    EbAvcStyleMcp_Intrinsic_SSE2.c
    EbAvcStyleMcp_SSE2.h
    EbDeblockingFilter_Intrinsic_SSE2.c
    EbDeblockingFilter_SSE2.h
    EbHighbdIntraPrediction_SSE2.h
    EbIntraPrediction_AV1_Intrinsic_SSE2.c
    EbMcp_Intrinsic_SSE2.c
    EbMcp_SSE2.h
    EbPackUnPack_Intrinsic_SSE2.c
    EbPictureOperators_Intrinsic_SSE2.c
    EbPictureOperators_SSE2.asm
    EbPictureOperators_SSE2.h
    highbd_intrapred_sse2.c
    highbd_intrapred_sse2_.asm
    highbd_subtract_sse2.c
    intrapred_sse2.asm
    lpf_common_sse2.h
    subtract_sse2.asm
    synonyms.h
    transpose_sse2.h
    )

add_library(COMMON_ASM_SSE2 OBJECT ${all_files})
