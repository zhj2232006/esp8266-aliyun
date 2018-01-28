/*
 * Copyright (c) 2014-2016 Alibaba Group. All rights reserved.
 * License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdio.h>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <Winbase.h>
#include <string.h>

#include "iot_import.h"

#define PLATFORM_WINSOCK_LOG(format, ...)                                                      \
    do                                                                                         \
    {                                                                                          \
        HAL_Printf("LINUXSOCK %u %s() | " format "\n", __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        fflush(stdout);                                                                        \
    } while (0);

#define PLATFORM_WINSOCK_PERROR(log)                                                                                \
    do                                                                                                              \
    {                                                                                                               \
        char* s = NULL;                                                                                             \
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, \
                       NULL,                                                                                                   \
                       WSAGetLastError(),                                                                                      \
                       MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),                                                           \
                       (LPSTR)&s,                                                                                              \
                       0,                                                                                                      \
                       NULL);                                                                                                  \
        HAL_Printf("[SOCK]%d %s() %s: %s", __LINE__, __FUNCTION__, log, s);                                         \
        LocalFree(s);                                                                                               \
    } while (0);
#include "iot_import_coap.h"

void* HAL_UDP_create(char* host, unsigned short port)
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}

void HAL_UDP_close(void* p_socket)
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}

int HAL_UDP_write(void* p_socket,
                  const unsigned char* p_data,
                  unsigned int datalen)
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}

int HAL_UDP_read(void* p_socket,
                 unsigned char* p_data,
                 unsigned int datalen)
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}

int HAL_UDP_readTimeout(void* p_socket, unsigned char* p_data,
                        unsigned int datalen, unsigned int timeout)
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}

int HAL_UDP_resolveAddress(const char* p_host, char addr[128])
{
    PLATFORM_WINSOCK_PERROR("todo implement");
}
