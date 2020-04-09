#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# ASM_SSE2 Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(../../../API
        ../../Encoder/Codec
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
     )

set(flags_to_test -msse2)

if(CMAKE_C_COMPILER_ID STREQUAL "Intel" AND NOT WIN32)
    list(APPEND flags_to_test -static-intel -w)
endif()

test_apply_compiler_flags(${flags_to_test})

set(all_files
    EbCombinedAveragingSAD_Intrinsic_SSE2.c
    EbComputeMean_Intrinsic_SSE2.c
    EbComputeMean_SSE2.h
    EbComputeSAD_SSE2.h
    EbMeSadCalculation_Intrinsic_SSE2.c
    EbVariance_SSE2.h
    encodetxb_sse2.c
    fft_sse2.c
    highbd_variance_impl_sse2.asm
    highbd_variance_sse2.c
    variance_sse2.c
    x64RegisterUtil.asm
    )

#list(REMOVE_ITEM all_files)


add_library(ENCODER_ASM_SSE2 OBJECT ${all_files})
