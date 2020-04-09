#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#
# Common/Codec Directory CMakeLists.txt

# Include Encoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX512/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Encoder/Codec/
    ${PROJECT_SOURCE_DIR}/third_party/fastfeat/)

set(all_files
    Av1Common.h
    common_dsp_rtcd.c
    common_dsp_rtcd.h
    convolve.c
    convolve.h
    EbAv1Structs.h
    EbAvcStyleMcp.c
    EbAvcStyleMcp.h
    EbBitstreamUnit.c
    EbBitstreamUnit.h
    EbBlend_a64_mask.c
    EbBlockStructures.c
    EbBlockStructures.h
    EbCabacContextModel.c
    EbCabacContextModel.h
    EbCdef.c
    EbCdef.h
    EbCoefficients.h
    EbCommonUtils.h
    EbDeblockingCommon.c
    EbDeblockingCommon.h
    EbDefinitions.h
    EbInterPrediction.c
    EbInterPrediction.h
    EbIntraCommon.h
    EbIntraPrediction.c
    EbIntraPrediction.h
    EbInvTransforms.c
    EbInvTransforms.h
    EbLog.c
    EbLog.h
    EbMalloc.c
    EbMalloc.h
    EbMcp.c
    EbMcp.h
    EbObject.h
    EbPackUnPack.h
    EbPictureBufferDesc.c
    EbPictureBufferDesc.h
    EbPictureOperators.c
    EbPictureOperators.h
    EbQMatrices.h
    EbRestoration.c
    EbRestoration.h
    EbSegmentationParams.c
    EbSegmentationParams.h
    EbSuperRes.c
    EbSuperRes.h
    EbSyntaxElements.h
    EbSystemResourceManager.c
    EbSystemResourceManager.h
    EbThreads.c
    EbThreads.h
    EbTime.c
    EbTime.h
    EbUtility.c
    EbUtility.h
    EbWarpedMotion.c
    EbWarpedMotion.h
    filter.h
    grainSynthesis.c
    grainSynthesis.h
    )

add_library(COMMON_CODEC OBJECT ${all_files})
