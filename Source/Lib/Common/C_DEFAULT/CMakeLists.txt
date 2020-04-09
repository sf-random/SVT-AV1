#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#

# C_DEFAULT Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/)

set(all_files
    cfl_c.c
    EbBlend_a64_mask_c.c
    EbInterPrediction_c.c
    EbIntraPrediction_c.c
    EbPackUnPack_C.c
    EbPackUnPack_C.h
    EbPictureOperators_C.c
    EbPictureOperators_C.h
    filterintra_c.c
    )

add_library(COMMON_C_DEFAULT OBJECT ${all_files})
