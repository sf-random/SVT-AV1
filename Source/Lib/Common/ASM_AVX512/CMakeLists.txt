#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# Common/ASM_AVX512 Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX512/)
link_directories(${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/)

set(flags_to_test
    -mavx2
    -mavx512f
    -mavx512bw
    -mavx512dq
    -mavx512vl)

if(MSVC)
    list(APPEND flags_to_test /arch:AVX2)
endif()

if(CMAKE_C_COMPILER_ID STREQUAL "Intel")
    if(WIN32)
        # Intel Windows (*Note - The Warning level /W0 should be made to /W4 at some point)
        list(APPEND flags_to_test /Qdiag-disable:10010,10148,10157 /W0)
    else()
        list(APPEND flags_to_test -static-intel -w)
    endif()
endif()

test_apply_compiler_flags(${flags_to_test})

set(all_files
    cdef_block_avx512.c
    convolve_2d_avx512.c
    convolve_avx512.c
    convolve_avx512.h
    EbHighbdIntraPrediction_AVX512.c
    EbPictureOperators_Intrinsic_AVX512.c
    highbd_inv_txfm_avx512.c
    jnt_convolve_2d_avx512.c
    jnt_convolve_avx512.c
    synonyms_avx512.h
    wiener_convolve_avx512.c
    )

add_library(COMMON_ASM_AVX512 OBJECT ${all_files})
