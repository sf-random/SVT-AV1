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

#ifndef EbPictureOperators_C_h
#define EbPictureOperators_C_h

#include "EbDefinitions.h"
#ifdef __cplusplus
extern "C" {
#endif

void picture_average_kernel_c(EbByte src0, uint32_t src0_stride, EbByte src1, uint32_t src1_stride,
                              EbByte dst, uint32_t dst_stride, uint32_t area_width,
                              uint32_t area_height);

void picture_average_kernel1_line_c(EbByte src0, EbByte src1, EbByte dst, uint32_t areaWidth);

void picture_copy_kernel(EbByte src, uint32_t src_stride, EbByte dst, uint32_t dst_stride,
                         uint32_t area_width, uint32_t area_height, uint32_t bytes_per_sample);

extern void picture_addition_kernel(uint8_t *pred_ptr, uint32_t pred_stride, int32_t *residual_ptr,
                                    uint32_t residual_stride, uint8_t *recon_ptr,
                                    uint32_t recon_stride, uint32_t width, uint32_t height,
                                    int32_t bd);

#ifdef __cplusplus
}
#endif
#endif // EbPictureOperators_C_h
