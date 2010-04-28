/**
   In short, stk is distributed under so called "BSD license",
   
   Copyright (c) 2010 Tatsuhiko Kubo <cubicdaiya@gmail.com>
   All rights reserved.
   
   Redistribution and use in source and binary forms, with or without modification, 
   are permitted provided that the following conditions are met:
   
   * Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.
   
   * Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.
   
   * Neither the name of the authors nor the names of its contributors 
   may be used to endorse or promote products derived from this software 
   without specific prior written permission.
   
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* written by C99 style */

#ifndef STK_H
#define STK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

#define STK_DEFALT_SIZE 72
#define STK_DEFALT_ELEM_SIZE (sizeof(int))

#define STK_MALLOC(p, n)                        \
    do {                                        \
        if (((p) = malloc(n)) == NULL) {        \
            fprintf(stderr, "malloc failed");   \
            exit(-1);                           \
        }                                       \
    } while(false)
#define STK_FREE(p)                             \
    do {                                        \
        free(p);                                \
        (p) = NULL;                             \
    } while(false)

#define STK_SIZ(vec)       (vec->siz)
#define STK_IDX(vec, idx)  (*(vec->arr + (vec->elemsiz * idx)))
#define STK_IDXP(vec, idx) (vec->arr + (vec->elemsiz * idx))

typedef unsigned char uchar_t;

typedef struct stk_s {
    uchar_t *arr;       // array's pointer
    size_t capa;        // capacity
    size_t siz;         // array size
    size_t elemsiz;     // elemment size
} stk_t;

stk_t *stk_create(size_t vecsiz, size_t elemsiz);
bool stk_push(stk_t *vec, const void *elem);
void stk_destroy(stk_t *vec);

#endif

