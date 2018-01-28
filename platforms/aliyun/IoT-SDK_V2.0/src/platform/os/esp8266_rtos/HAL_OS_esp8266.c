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


#include <time.h>
#include <reent.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <pthread.h>
#include <unistd.h>
// #include <sys/time.h>
#include "freertos/FreeRTOS.h"

#include "iot_import.h"


int _getpid_r(struct _reent *par)
{

}

int _kill_r(struct _reent *a, int b, int c)
{

}

void mygettimeofday(struct timeval *tv, void *tz)
{
    struct _reent r;
    _gettimeofday_r(&r, tv, tz);

}


void *HAL_MutexCreate(void)
{
    return NULL;
}

void HAL_MutexDestroy(_IN_ void *mutex)
{

}

void HAL_MutexLock(_IN_ void *mutex)
{

}

void HAL_MutexUnlock(_IN_ void *mutex)
{

}

void *HAL_Malloc(_IN_ uint32_t size)
{
    return malloc(size);
}

void HAL_Free(_IN_ void *ptr)
{
    return free(ptr);
}

uint64_t HAL_UptimeMs(void)
{
    struct timeval tv = { 0 };
    uint32_t time_ms;

    mygettimeofday(&tv, NULL);

    time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    return time_ms;
}

void HAL_SleepMs(_IN_ uint32_t ms)
{
    // usleep(1000 * ms);
    if ((ms > 0) && (ms < portTICK_RATE_MS)) {
        ms = portTICK_RATE_MS;
    }

    vTaskDelay(ms / portTICK_RATE_MS);
}

void HAL_Srandom(uint32_t seed)
{
    //srandom(seed);
}

uint32_t HAL_Random(uint32_t region)
{
    //return (region > 0) ? (random() % region) : 0;
	return 0;
}
int HAL_Snprintf(_IN_ char *str, const int len, const char *fmt, ...)
{
    va_list args;
    int     rc;

    va_start(args, fmt);
    rc = vsnprintf(str, len, fmt, args);
    va_end(args);

    return rc;
}

int HAL_Vsnprintf(_IN_ char *str, _IN_ const int len, _IN_ const char *format, va_list ap)
{
    return vsnprintf(str, len, format, ap);
}
void HAL_Printf(_IN_ const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    fflush(stdout);
}
int HAL_GetPartnerID(char pid_str[])
{
    return 0;
}
int HAL_GetModuleID(char mid_str[MID_STRLEN_MAX])
{
    memset(mid_str, 0x0, MID_STRLEN_MAX);
#ifdef __UBUNTU_SDK_DEMO__
    strcpy(mid_str, "example.demo.module-id");
#endif
    return strlen(mid_str);
}
