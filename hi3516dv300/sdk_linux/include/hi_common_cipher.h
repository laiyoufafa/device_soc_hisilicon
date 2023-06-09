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

#ifndef __HI_COMMON_CIPHER_H__
#define __HI_COMMON_CIPHER_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define  HI_ERR_CIPHER_NOT_INIT                             0x804D0001
#define  HI_ERR_CIPHER_INVALID_HANDLE                       0x804D0002
#define  HI_ERR_CIPHER_INVALID_POINT                        0x804D0003
#define  HI_ERR_CIPHER_INVALID_PARA                         0x804D0004
#define  HI_ERR_CIPHER_FAILED_INIT                          0x804D0005
#define  HI_ERR_CIPHER_FAILED_GETHANDLE                     0x804D0006
#define  HI_ERR_CIPHER_FAILED_RELEASEHANDLE                 0x804D0007
#define  HI_ERR_CIPHER_FAILED_CONFIGAES                     0x804D0008
#define  HI_ERR_CIPHER_FAILED_CONFIGDES                     0x804D0009
#define  HI_ERR_CIPHER_FAILED_ENCRYPT                       0x804D000A
#define  HI_ERR_CIPHER_FAILED_DECRYPT                       0x804D000B
#define  HI_ERR_CIPHER_BUSY                                 0x804D000C
#define  HI_ERR_CIPHER_NO_AVAILABLE_RNG                     0x804D000D
#define  HI_ERR_CIPHER_FAILED_MEM                           0x804D000E
#define  HI_ERR_CIPHER_UNAVAILABLE                          0x804D000F
#define  HI_ERR_CIPHER_OVERFLOW                             0x804D0010
#define  HI_ERR_CIPHER_HARD_STATUS                          0x804D0011
#define  HI_ERR_CIPHER_TIMEOUT                              0x804D0012
#define  HI_ERR_CIPHER_UNSUPPORTED                          0x804D0013
#define  HI_ERR_CIPHER_REGISTER_IRQ                         0x804D0014
#define  HI_ERR_CIPHER_ILLEGAL_UUID                         0x804D0015
#define  HI_ERR_CIPHER_ILLEGAL_KEY                          0x804D0016
#define  HI_ERR_CIPHER_INVALID_ADDR                         0x804D0017
#define  HI_ERR_CIPHER_INVALID_LENGTH                       0x804D0018
#define  HI_ERR_CIPHER_ILLEGAL_DATA                         0x804D0019
#define  HI_ERR_CIPHER_RSA_SIGN                             0x804D001A
#define  HI_ERR_CIPHER_RSA_VERIFY                           0x804D001B
#define  HI_ERR_CIPHER_MEMSET_S_FAILED                      0x804D001C
#define  HI_ERR_CIPHER_MEMCPY_S_FAILED                      0x804D001D
#define  HI_ERR_CIPHER_RSA_CRYPT_FAILED                     0x804D001E

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_COMMON_CIPHER_H__ */
