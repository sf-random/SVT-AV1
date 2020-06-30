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

#ifndef EbInitialRateControlResults_h
#define EbInitialRateControlResults_h

#include "EbDefinitions.h"
#include "EbSystemResourceManager.h"
#include "EbObject.h"

/**************************************
 * Process Results
 **************************************/
typedef struct InitialRateControlResults {
    EbDctor          dctor;
    EbObjectWrapper *pcs_wrapper_ptr;
} InitialRateControlResults;

typedef struct InitialRateControlResultInitData {
    int32_t junk;
} InitialRateControlResultInitData;

/**************************************
 * Extern Function Declarations
 **************************************/
extern EbErrorType initial_rate_control_results_creator(EbPtr *object_dbl_ptr,
                                                        EbPtr  object_init_data_ptr);

#endif //EbInitialRateControlResults_h
