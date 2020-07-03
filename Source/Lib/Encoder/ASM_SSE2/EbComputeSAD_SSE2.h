/*
* Copyright (c) 2019, Alliance for Open Media. All rights reserved
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at www.aomedia.org/license/software. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at www.aomedia.org/license/patent.
*/

#ifndef EbComputeSAD_SSE2_h
#define EbComputeSAD_SSE2_h

#include "EbDefinitions.h"
#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t combined_averaging_4xm_sad_sse2_intrin(uint8_t *src, uint32_t src_stride,
                                                       uint8_t *ref1, uint32_t ref1_stride,
                                                       uint8_t *ref2, uint32_t ref2_stride,
                                                       uint32_t height, uint32_t width);

#ifdef __cplusplus
}
#endif
#endif // EbComputeSAD_SSE2_h
