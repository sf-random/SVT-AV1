/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbPredictionUnit_h
#define EbPredictionUnit_h

#include "EbDefinitions.h"
#include "EbSyntaxElements.h"
#include "EbDefinitions.h"
#include "EbMotionVectorUnit.h"
#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1)
typedef struct PredictionUnit {
    Mv mv[MAX_NUM_OF_REF_PIC_LIST]; //ec
    uint8_t inter_pred_direction_index; // ec
    // Intra Mode
    int32_t  angle_delta[PLANE_TYPES]; // ec
    EbBool is_directional_mode_flag; // ec
    EbBool is_directional_chroma_mode_flag; // ec
    uint32_t intra_chroma_mode; // ec

    // Inter Mode
    PredictionMode inter_mode; // ec
    EbBool is_compound; // ec
    uint8_t ref_frame_type; // ec
    MotionMode motion_mode; // ec
    uint16_t num_proj_ref; // ec
    uint32_t overlappable_neighbors[2]; // ec
    // Index of the alpha Cb and alpha Cr combination
    int32_t cfl_alpha_idx; // ec
    // Joint sign of alpha Cb and alpha Cr
    int32_t cfl_alpha_signs; // ec
} PredictionUnit;
#pragma pack(pop)

#ifdef __cplusplus
}
#endif
#endif //EbPredictionUnit_h
