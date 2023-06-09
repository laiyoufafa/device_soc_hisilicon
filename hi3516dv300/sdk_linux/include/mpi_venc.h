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
#ifndef __MPI_VENC_H__
#define __MPI_VENC_H__

#include "hi_common.h"
#include "hi_comm_video.h"
#include "hi_comm_venc.h"
#include "hi_comm_vb.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

HI_S32 HI_MPI_VENC_CreateChn(VENC_CHN VeChn, const VENC_CHN_ATTR_S *pstAttr);
HI_S32 HI_MPI_VENC_DestroyChn(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_ResetChn(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_StartRecvFrame(VENC_CHN VeChn, const VENC_RECV_PIC_PARAM_S *pstRecvParam);
HI_S32 HI_MPI_VENC_StopRecvFrame(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_QueryStatus(VENC_CHN VeChn, VENC_CHN_STATUS_S *pstStatus);
HI_S32 HI_MPI_VENC_SetChnAttr(VENC_CHN VeChn, const VENC_CHN_ATTR_S *pstChnAttr);
HI_S32 HI_MPI_VENC_GetChnAttr(VENC_CHN VeChn, VENC_CHN_ATTR_S *pstChnAttr);
HI_S32 HI_MPI_VENC_GetStream(VENC_CHN VeChn, VENC_STREAM_S *pstStream, HI_S32 s32MilliSec);
HI_S32 HI_MPI_VENC_ReleaseStream(VENC_CHN VeChn, VENC_STREAM_S *pstStream);
HI_S32 HI_MPI_VENC_InsertUserData(VENC_CHN VeChn, HI_U8 *pu8Data, HI_U32 u32Len);
HI_S32 HI_MPI_VENC_SendFrame(VENC_CHN VeChn, const VIDEO_FRAME_INFO_S *pstFrame, HI_S32 s32MilliSec);
HI_S32 HI_MPI_VENC_SendFrameEx(VENC_CHN VeChn, const USER_FRAME_INFO_S *pstFrame, HI_S32 s32MilliSec);
HI_S32 HI_MPI_VENC_SendMultiFrame(VENC_CHN VeChn, const MULTI_FRAME_INFO_S *pstMultiFrame, HI_S32 s32MilliSec);
HI_S32 HI_MPI_VENC_SetChnConfig(VENC_CHN VeChn, const VENC_CHN_CONFIG_S *pstChnConfig);
HI_S32 HI_MPI_VENC_GetChnConfig(VENC_CHN VeChn, VENC_CHN_CONFIG_S *pstChnConfig);
HI_S32 HI_MPI_VENC_RequestIDR(VENC_CHN VeChn, HI_BOOL bInstant);
HI_S32 HI_MPI_VENC_GetFd(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_CloseFd(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_SetRoiAttr(VENC_CHN VeChn, const VENC_ROI_ATTR_S *pstRoiAttr);
HI_S32 HI_MPI_VENC_GetRoiAttr(VENC_CHN VeChn, HI_U32 u32Index, VENC_ROI_ATTR_S *pstRoiAttr);
HI_S32 HI_MPI_VENC_GetRoiAttrEx(VENC_CHN VeChn, HI_U32 u32Index, VENC_ROI_ATTR_EX_S *pstRoiAttrEx);
HI_S32 HI_MPI_VENC_SetRoiAttrEx(VENC_CHN VeChn, const VENC_ROI_ATTR_EX_S *pstRoiAttrEx);
HI_S32 HI_MPI_VENC_SetRoiBgFrameRate(VENC_CHN VeChn, const VENC_ROIBG_FRAME_RATE_S *pstRoiBgFrmRate);
HI_S32 HI_MPI_VENC_GetRoiBgFrameRate(VENC_CHN VeChn, VENC_ROIBG_FRAME_RATE_S *pstRoiBgFrmRate);
HI_S32 HI_MPI_VENC_SetH264SliceSplit(VENC_CHN VeChn, const VENC_H264_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_GetH264SliceSplit(VENC_CHN VeChn, VENC_H264_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_SetH264IntraPred(VENC_CHN VeChn, const VENC_H264_INTRA_PRED_S *pstH264IntraPred);
HI_S32 HI_MPI_VENC_GetH264IntraPred(VENC_CHN VeChn, VENC_H264_INTRA_PRED_S *pstH264IntraPred);
HI_S32 HI_MPI_VENC_SetH264Trans(VENC_CHN VeChn, const VENC_H264_TRANS_S *pstH264Trans);
HI_S32 HI_MPI_VENC_GetH264Trans(VENC_CHN VeChn, VENC_H264_TRANS_S *pstH264Trans);
HI_S32 HI_MPI_VENC_SetH264Entropy(VENC_CHN VeChn, const VENC_H264_ENTROPY_S *pstH264EntropyEnc);
HI_S32 HI_MPI_VENC_GetH264Entropy(VENC_CHN VeChn, VENC_H264_ENTROPY_S *pstH264EntropyEnc);
HI_S32 HI_MPI_VENC_SetH264Dblk(VENC_CHN VeChn, const VENC_H264_DBLK_S *pstH264Dblk);
HI_S32 HI_MPI_VENC_GetH264Dblk(VENC_CHN VeChn, VENC_H264_DBLK_S *pstH264Dblk);
HI_S32 HI_MPI_VENC_SetH264Vui(VENC_CHN VeChn, const VENC_H264_VUI_S *pstH264Vui);
HI_S32 HI_MPI_VENC_GetH264Vui(VENC_CHN VeChn, VENC_H264_VUI_S *pstH264Vui);
HI_S32 HI_MPI_VENC_SetH264Poc(VENC_CHN VeChn, const VENC_H264_POC_S *pstH264Poc);
HI_S32 HI_MPI_VENC_GetH264Poc(VENC_CHN VeChn, VENC_H264_POC_S *pstH264Poc);
HI_S32 HI_MPI_VENC_SetH265Vui(VENC_CHN VeChn, const VENC_H265_VUI_S *pstH265Vui);
HI_S32 HI_MPI_VENC_GetH265Vui(VENC_CHN VeChn, VENC_H265_VUI_S *pstH265Vui);
HI_S32 HI_MPI_VENC_SetJpegParam(VENC_CHN VeChn, const VENC_JPEG_PARAM_S *pstJpegParam);
HI_S32 HI_MPI_VENC_GetJpegParam(VENC_CHN VeChn, VENC_JPEG_PARAM_S *pstJpegParam);
HI_S32 HI_MPI_VENC_SetMjpegParam(VENC_CHN VeChn, const VENC_MJPEG_PARAM_S *pstMjpegParam);
HI_S32 HI_MPI_VENC_GetMjpegParam(VENC_CHN VeChn, VENC_MJPEG_PARAM_S *pstMjpegParam);
HI_S32 HI_MPI_VENC_GetRcParam(VENC_CHN VeChn, VENC_RC_PARAM_S *pstRcParam);
HI_S32 HI_MPI_VENC_SetRcParam(VENC_CHN VeChn, const VENC_RC_PARAM_S *pstRcParam);
HI_S32 HI_MPI_VENC_SetRefParam(VENC_CHN VeChn, const VENC_REF_PARAM_S *pstRefParam);
HI_S32 HI_MPI_VENC_GetRefParam(VENC_CHN VeChn, VENC_REF_PARAM_S *pstRefParam);
HI_S32 HI_MPI_VENC_SetJpegEncodeMode(VENC_CHN VeChn, const VENC_JPEG_ENCODE_MODE_E enJpegEncodeMode);
HI_S32 HI_MPI_VENC_GetJpegEncodeMode(VENC_CHN VeChn, VENC_JPEG_ENCODE_MODE_E *penJpegEncodeMode);
HI_S32 HI_MPI_VENC_EnableIDR(VENC_CHN VeChn, HI_BOOL bEnableIDR);
HI_S32 HI_MPI_VENC_GetStreamBufInfo(VENC_CHN VeChn, VENC_STREAM_BUF_INFO_S *pstStreamBufInfo);
HI_S32 HI_MPI_VENC_SetH265SliceSplit(VENC_CHN VeChn, const VENC_H265_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_GetH265SliceSplit(VENC_CHN VeChn, VENC_H265_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_SetH265PredUnit(VENC_CHN VeChn, const VENC_H265_PU_S *pstPredUnit);
HI_S32 HI_MPI_VENC_GetH265PredUnit(VENC_CHN VeChn, VENC_H265_PU_S *pstPredUnit);
HI_S32 HI_MPI_VENC_SetH265Trans(VENC_CHN VeChn, const VENC_H265_TRANS_S *pstH265Trans);
HI_S32 HI_MPI_VENC_GetH265Trans(VENC_CHN VeChn, VENC_H265_TRANS_S *pstH265Trans);
HI_S32 HI_MPI_VENC_SetH265Entropy(VENC_CHN VeChn, const VENC_H265_ENTROPY_S *pstH265Entropy);
HI_S32 HI_MPI_VENC_GetH265Entropy(VENC_CHN VeChn, VENC_H265_ENTROPY_S *pstH265Entropy);
HI_S32 HI_MPI_VENC_SetH265Dblk(VENC_CHN VeChn, const VENC_H265_DBLK_S *pstH265Dblk);
HI_S32 HI_MPI_VENC_GetH265Dblk(VENC_CHN VeChn, VENC_H265_DBLK_S *pstH265Dblk);
HI_S32 HI_MPI_VENC_SetH265Sao(VENC_CHN VeChn, const VENC_H265_SAO_S *pstH265Sao);
HI_S32 HI_MPI_VENC_GetH265Sao(VENC_CHN VeChn, VENC_H265_SAO_S *pstH265Sao);
HI_S32 HI_MPI_VENC_SetFrameLostStrategy(VENC_CHN VeChn, const VENC_FRAMELOST_S *pstFrmLostParam);
HI_S32 HI_MPI_VENC_GetFrameLostStrategy(VENC_CHN VeChn, VENC_FRAMELOST_S *pstFrmLostParam);
HI_S32 HI_MPI_VENC_SetSuperFrameStrategy(VENC_CHN VeChn, const VENC_SUPERFRAME_CFG_S *pstSuperFrmParam);
HI_S32 HI_MPI_VENC_GetSuperFrameStrategy(VENC_CHN VeChn, VENC_SUPERFRAME_CFG_S *pstSuperFrmParam);
HI_S32 HI_MPI_VENC_SetIntraRefresh(VENC_CHN VeChn, const VENC_INTRA_REFRESH_S *pstIntraRefresh);
HI_S32 HI_MPI_VENC_GetIntraRefresh(VENC_CHN VeChn, VENC_INTRA_REFRESH_S *pstIntraRefresh);
HI_S32 HI_MPI_VENC_GetSSERegion(VENC_CHN VeChn, HI_U32 u32Index, VENC_SSE_CFG_S *pstSSECfg);
HI_S32 HI_MPI_VENC_SetSSERegion(VENC_CHN VeChn, const VENC_SSE_CFG_S *pstSSECfg);
HI_S32 HI_MPI_VENC_SetChnParam(VENC_CHN VeChn, const VENC_CHN_PARAM_S *pstChnParam);
HI_S32 HI_MPI_VENC_GetChnParam(VENC_CHN VeChn, VENC_CHN_PARAM_S *pstChnParam);
HI_S32 HI_MPI_VENC_SetModParam(const VENC_PARAM_MOD_S *pstModParam);
HI_S32 HI_MPI_VENC_GetModParam(VENC_PARAM_MOD_S *pstModParam);
HI_S32 HI_MPI_VENC_GetForegroundProtect(VENC_CHN VeChn, VENC_FOREGROUND_PROTECT_S *pstForegroundProtect);
HI_S32 HI_MPI_VENC_SetForegroundProtect(VENC_CHN VeChn, const VENC_FOREGROUND_PROTECT_S *pstForegroundProtect);
HI_S32 HI_MPI_VENC_SetSceneMode(VENC_CHN VeChn, const VENC_SCENE_MODE_E enSceneMode);
HI_S32 HI_MPI_VENC_GetSceneMode(VENC_CHN VeChn, VENC_SCENE_MODE_E *penSceneMode);
HI_S32 HI_MPI_VENC_AttachVbPool(VENC_CHN VeChn, const VENC_CHN_POOL_S *pstPool);
HI_S32 HI_MPI_VENC_DetachVbPool(VENC_CHN VeChn);
HI_S32 HI_MPI_VENC_SetCuPrediction(VENC_CHN VeChn, const VENC_CU_PREDICTION_S *pstCuPrediction);
HI_S32 HI_MPI_VENC_GetCuPrediction(VENC_CHN VeChn, VENC_CU_PREDICTION_S *pstCuPrediction);
HI_S32 HI_MPI_VENC_SetSkipBias(VENC_CHN VeChn, const VENC_SKIP_BIAS_S *pstSkipBias);
HI_S32 HI_MPI_VENC_GetSkipBias(VENC_CHN VeChn, VENC_SKIP_BIAS_S *pstSkipBias);
HI_S32 HI_MPI_VENC_SetDeBreathEffect(VENC_CHN VeChn, const VENC_DEBREATHEFFECT_S *pstDeBreathEffect);
HI_S32 HI_MPI_VENC_GetDeBreathEffect(VENC_CHN VeChn, VENC_DEBREATHEFFECT_S *pstDeBreathEffect);
HI_S32 HI_MPI_VENC_SetHierarchicalQp(VENC_CHN VeChn, const VENC_HIERARCHICAL_QP_S *pstHierarchicalQp);
HI_S32 HI_MPI_VENC_GetHierarchicalQp(VENC_CHN VeChn, VENC_HIERARCHICAL_QP_S *pstHierarchicalQp);
HI_S32 HI_MPI_VENC_SetRcAdvParam(VENC_CHN VeChn, const VENC_RC_ADVPARAM_S *pstRcAdvParam);
HI_S32 HI_MPI_VENC_GetRcAdvParam(VENC_CHN VeChn, VENC_RC_ADVPARAM_S *pstRcAdvParam);
HI_S32 HI_MPI_VENC_SetSliceSplit(VENC_CHN VeChn, const VENC_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_GetSliceSplit(VENC_CHN VeChn, VENC_SLICE_SPLIT_S *pstSliceSplit);
HI_S32 HI_MPI_VENC_SetSearchWindow(VENC_CHN VeChn, const VENC_SEARCH_WINDOW_S *pstSearchWindow);
HI_S32 HI_MPI_VENC_GetSearchWindow(VENC_CHN VeChn, VENC_SEARCH_WINDOW_S *pstSearchWindow);
HI_S32 HI_MPI_VENC_EnableSvc(VENC_CHN VeChn, HI_BOOL bEnable);
HI_S32 HI_MPI_VENC_SetSvcParam(VENC_CHN VeChn, const VENC_SVC_PARAM_S *pstSvcParam);
HI_S32 HI_MPI_VENC_GetSvcParam(VENC_CHN VeChn, VENC_SVC_PARAM_S *pstSvcParam);
HI_S32 HI_MPI_VENC_GetSvcSceneComplexity(VENC_CHN VeChn, VENC_SVC_DETECT_RESULT_S *pstSvcDetectResult);
HI_S32 HI_MPI_VENC_SendSvcRegion(VENC_CHN VeChn, VENC_SVC_RECT_INFO_S *pstSvcRegion);
HI_S32 HI_MPI_VENC_SetParamId(VENC_CHN VeChn, const VENC_PARAM_SET_ID_S *pstParamSetId);
HI_S32 HI_MPI_VENC_GetParamId(VENC_CHN VeChn, VENC_PARAM_SET_ID_S *pstParamSetId);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MPI_VENC_H__ */

