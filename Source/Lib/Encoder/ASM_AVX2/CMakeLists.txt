#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# Encoder/ASM_AVX2 Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(../../../API
        ../../Encoder/Codec
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_AVX512/)
link_directories(${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/ASM_SSSE3/)

set(flags_to_test -mavx2)

if(CMAKE_C_COMPILER_ID STREQUAL "Intel")
    if(WIN32)
        # Intel Windows (*Note - The Warning level /W0 should be made to /W4 at some point)
        list(APPEND flags_to_test /Qdiag-disable:10010,10148,10157 /W0)
    else()
        list(APPEND flags_to_test -static-intel -w)
    endif()
endif()

if(MSVC)
    list(APPEND flags_to_test /arch:AVX2)
endif()

test_apply_compiler_flags(${flags_to_test})

set(all_files
    EbCombinedAveragingSAD_Inline_AVX2.h
    EbCombinedAveragingSAD_Intrinsic_AVX2.h
    EbComputeSAD_AVX2.h
    pickrst_avx2.h
    EbCdef_AVX2.c
    EbCombinedAveragingSAD_Intrinsic_AVX2.c
    EbComputeSAD_Intrinsic_AVX2.c
    EbRestorationPick_AVX2.c
    EbTemporalFiltering_AVX2.c
    EbTransforms_Intrinsic_AVX2.c
    av1_quantize_avx2.c
    corner_match_avx2.c
    enc_warp_plane_avx2.c
    encodetxb_avx2.c
    fft_avx2.c
    highbd_fwd_txfm_avx2.c
    highbd_quantize_intrin_avx2.c
    highbd_variance_avx2.c
    obmc_sad_avx2.c
    obmc_variance_avx2.c
    palette_avx2.c
    pickrst_avx2.c
    sse_avx2.c
    variance_avx2.c
    )

add_library(ENCODER_ASM_AVX2 OBJECT ${all_files})
