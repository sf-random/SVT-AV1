#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# C_DEFAULT Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(../../../API
        ../../Encoder/Codec
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/C_DEFAULT/)

set(all_files
    EbComputeSAD_C.c
    EbComputeSAD_C.h
    EbComputeVariance_C.c
    EbComputeVariance_C.h
    EncodeTxbRef_C.c
    EncodeTxbRef_C.h
    sad_av1
    variance.c
    )

add_library(ENCODER_C_DEFAULT OBJECT ${all_files})
