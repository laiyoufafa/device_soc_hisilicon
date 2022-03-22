/*
 * Copyright (c) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SAMPLE_LCD_H
#define SAMPLE_LCD_H

#include <stdint.h>
#include "sample_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#ifndef SAMPLE_PRT
#define SAMPLE_PRT(fmt...) \
    do { \
        printf("[%s]-%d: ", __FUNCTION__, __LINE__); \
        printf(fmt); \
    } while (0)
#endif

typedef SAMPLE_VI_CONFIG_S ViCfg;

typedef struct SampleStoreInfo {
    SIZE_S stSize[2];
    VENC_GOP_MODE_E enGopMode;
    VENC_GOP_ATTR_S stGopAttr;
    SAMPLE_RC_E     enRcMode;
    ViCfg viCfg;
} SampleStoreInfo;

int SAMPLE_VENC_H265_H264(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef SAMPLE_STORE_H */
