/* ====================================================================
 * Copyright (c) 2015 - 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */
/*
 * Paillier's Cryptosystem
 */

#ifndef HEADER_PAILLIER_H
#define HEADER_PAILLIER_H
#ifndef NO_GMSSL

#include <openssl/bn.h>
#include <openssl/asn1.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct paillier_st PAILLIER;

PAILLIER *PAILLIER_new(void);
void PAILLIER_free(PAILLIER *key);

int PAILLIER_generate_key(PAILLIER *key, int bits);
int PAILLIER_check_key(PAILLIER *key);
int PAILLIER_encrypt(BIGNUM *out, const BIGNUM *in, PAILLIER *key);
int PAILLIER_decrypt(BIGNUM *out, const BIGNUM *in, PAILLIER *key);
int PAILLIER_ciphertext_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, PAILLIER *key);
int PAILLIER_ciphertext_scalar_mul(BIGNUM *r, const BIGNUM *scalar, const BIGNUM *a, PAILLIER *key);

int PAILLIER_up_ref(PAILLIER *key);

DECLARE_ASN1_ENCODE_FUNCTIONS_const(PAILLIER, PaillierPrivateKey)
DECLARE_ASN1_ENCODE_FUNCTIONS_const(PAILLIER, PaillierPublicKey)

/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_PAILLIER_strings(void);

/* Error codes for the PAILLIER functions. */

/* Function codes. */
# define PAILLIER_F_PAILLIER_CHECK_KEY                    100
# define PAILLIER_F_PAILLIER_CIPHERTEXT_ADD               101
# define PAILLIER_F_PAILLIER_CIPHERTEXT_SCALAR_MUL        102
# define PAILLIER_F_PAILLIER_DECRYPT                      103
# define PAILLIER_F_PAILLIER_ENCRYPT                      104
# define PAILLIER_F_PAILLIER_GENERATE_KEY                 105
# define PAILLIER_F_PAILLIER_NEW                          106
# define PAILLIER_F_PAILLIER_PUB_DECODE                   107
# define PAILLIER_F_PKEY_PAILLIER_DECRYPT                 108
# define PAILLIER_F_PKEY_PAILLIER_ENCRYPT                 109

/* Reason codes. */
# define PAILLIER_R_BUFFER_TOO_SMALL                      104
# define PAILLIER_R_GENERATE_PRIME_FAILED                 100
# define PAILLIER_R_INVALID_PLAINTEXT                     101
# define PAILLIER_R_MALLOC_FAILED                         102
# define PAILLIER_R_NOT_IMPLEMENTED                       103

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
