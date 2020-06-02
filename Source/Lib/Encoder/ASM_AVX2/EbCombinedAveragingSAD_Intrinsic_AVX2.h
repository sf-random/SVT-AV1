/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/
#ifndef EbCombinedAveragingSAD_AVX2_h
#define EbCombinedAveragingSAD_AVX2_h

#include "EbDefinitions.h"
#ifdef __cplusplus
extern "C" {
#endif
void compute_interm_var_four8x8_avx2_intrin(uint8_t *input_samples, uint16_t input_stride,
                                            uint64_t *mean_of8x8_blocks, // mean of four  8x8
                                            uint64_t *mean_of_squared8x8_blocks);
#ifdef __cplusplus
}
#endif
#endif
