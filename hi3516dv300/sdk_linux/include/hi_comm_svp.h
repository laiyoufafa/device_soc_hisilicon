/*
 * Copyright (c) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HI_COMM_SVP_H__
#define __HI_COMM_SVP_H__

#include "hi_type.h"
#include "hi_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define HI_SVP_IMG_ADDR_NUM 3
#define HI_SVP_IMG_STRIDE_NUM 3

/* Blob type */
typedef enum hiSVP_BLOB_TYPE_E {
    SVP_BLOB_TYPE_S32       =  0x0,

    SVP_BLOB_TYPE_U8        =  0x1,

    /* channel is 3 */
    SVP_BLOB_TYPE_YVU420SP  =  0x2,

    /* channel is 3 */
    SVP_BLOB_TYPE_YVU422SP  =  0x3,

    SVP_BLOB_TYPE_VEC_S32   =  0x4,

    SVP_BLOB_TYPE_SEQ_S32   =  0x5,

    SVP_BLOB_TYPE_BUTT
} SVP_BLOB_TYPE_E;

/*
 * Blob struct
 * In Caffe, the blob contain shape info as the following order:
 * Image\FeatureMap:               N       C       H       W
 * FC(normal vector):              N       C
 * RNN\LSTM(Recurrent) vector:     T       N       D
 *
 * The relationship of the following blob struct with Caffe blob is as follows:
 * Image\FeatureMap:               Num    Chn    Height   With
 * FC(VEC_S32):                    Num    Width
 * RNN\LSTM(SEQ_S32) vector:       Step   Num     Dim
 * The stride, which measuring unit is byte, is always algined by the width or
 * dim direction.
 */
typedef struct hiSVP_BLOB_S {
    SVP_BLOB_TYPE_E enType;     /* Blob type */
    HI_U32 u32Stride;           /* Stride, a line bytes num */

    HI_U64 u64VirAddr;          /* virtual addr */
    HI_U64 u64PhyAddr;          /* physical addr */

    HI_U32 u32Num;             /* N: frame num or sequence num, correspond to caffe blob's n */
    union {
        struct {
            HI_U32 u32Width;    /* W: frame width, correspond to caffe blob's w */
            HI_U32 u32Height;   /* H: frame height, correspond to caffe blob's h */
            HI_U32 u32Chn;      /* C: frame channel, correspond to caffe blob's c */
        } stWhc;
        struct {
            HI_U32 u32Dim;          /* D: vecotr dimension */
            HI_U64 u64VirAddrStep;  /* T: virtual adress of time steps array in each sequence */
        } stSeq;
    } unShape;
} SVP_BLOB_S;

typedef SVP_BLOB_S  SVP_SRC_BLOB_S;
typedef SVP_BLOB_S  SVP_DST_BLOB_S;

/* Mem information */
typedef struct hiSVP_MEM_INFO_S {
    HI_U64  u64PhyAddr; /* RW;The physical address of the memory */
    HI_U64  u64VirAddr; /* RW;The virtual address of the memory */
    HI_U32  u32Size;    /* RW;The size of memory */
} SVP_MEM_INFO_S;

typedef SVP_MEM_INFO_S SVP_SRC_MEM_INFO_S;
typedef SVP_MEM_INFO_S SVP_DST_MEM_INFO_S;

/* Image type */
typedef enum hiSVP_IMAGE_TYPE_E {
    SVP_IMAGE_TYPE_U8C1           =  0x0,
    SVP_IMAGE_TYPE_S8C1           =  0x1,

    SVP_IMAGE_TYPE_YUV420SP       =  0x2,       /* YUV420 SemiPlanar */
    SVP_IMAGE_TYPE_YUV422SP       =  0x3,       /* YUV422 SemiPlanar */
    SVP_IMAGE_TYPE_YUV420P        =  0x4,       /* YUV420 Planar */
    SVP_IMAGE_TYPE_YUV422P        =  0x5,       /* YUV422 planar */

    SVP_IMAGE_TYPE_S8C2_PACKAGE   =  0x6,
    SVP_IMAGE_TYPE_S8C2_PLANAR    =  0x7,

    SVP_IMAGE_TYPE_S16C1          =  0x8,
    SVP_IMAGE_TYPE_U16C1          =  0x9,

    SVP_IMAGE_TYPE_U8C3_PACKAGE   =  0xa,
    SVP_IMAGE_TYPE_U8C3_PLANAR    =  0xb,

    SVP_IMAGE_TYPE_S32C1          =  0xc,
    SVP_IMAGE_TYPE_U32C1          =  0xd,

    SVP_IMAGE_TYPE_S64C1          =  0xe,
    SVP_IMAGE_TYPE_U64C1          =  0xf,

    SVP_IMAGE_TYPE_BUTT
} SVP_IMAGE_TYPE_E;

/* Image */
typedef struct hiSVP_IMAGE_S {
    HI_U64  au64PhyAddr[HI_SVP_IMG_ADDR_NUM]; /* RW;The physical address of the image */
    HI_U64  au64VirAddr[HI_SVP_IMG_ADDR_NUM]; /* RW;The virtual address of the image */
    HI_U32  au32Stride[HI_SVP_IMG_STRIDE_NUM];  /* RW;The stride of the image */
    HI_U32  u32Width;       /* RW;The width of the image */
    HI_U32  u32Height;      /* RW;The height of the image */
    SVP_IMAGE_TYPE_E  enType; /* RW;The type of the image */
} SVP_IMAGE_S;

typedef SVP_IMAGE_S SVP_SRC_IMAGE_S;
typedef SVP_IMAGE_S SVP_DST_IMAGE_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_COMM_SVP_H__ */
