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

#include "stk.h"

/**
 * create vector
 */
stk_t *stk_create(size_t capasiz, size_t elemsiz) {
    stk_t *vec;
    STK_MALLOC(vec, sizeof(stk_t));
    if (capasiz <= 0) {
        capasiz = STK_DEFALT_SIZE;
    }
    if (elemsiz <= 0) {
        elemsiz = STK_DEFALT_ELEM_SIZE;
    }
    vec->capa = capasiz;
    vec->siz = 0;
    vec->elemsiz = elemsiz;
    STK_MALLOC(vec->arr, elemsiz * capasiz);
    return vec;
}

/**
 * push an element to vector
 */
bool stk_push(stk_t *vec, const void *elem) {
    if (vec->siz >= vec->capa) {
        uchar_t *tmp = realloc(vec->arr, (vec->elemsiz * vec->capa) * 2);
        if (tmp == NULL) {
            return false;
        }
        vec->arr = tmp;
        vec->capa *= 2;
    }
    uchar_t *arr_idx = (uchar_t *)STK_IDXP(vec, vec->siz);
    memcpy(arr_idx, elem, vec->elemsiz);
    vec->siz++;
    return true;
}

/**
 * release vector
 */
void stk_destroy(stk_t *vec) {
    STK_FREE(vec->arr);
    STK_FREE(vec);
}


