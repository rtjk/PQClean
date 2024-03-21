/**
 *
 * Reference ISO-C11 Implementation of CROSS.
 *
 * @version 1.1 (March 2023)
 *
 * @author Alessandro Barenghi <alessandro.barenghi@polimi.it>
 * @author Gerardo Pelosi <gerardo.pelosi@polimi.it>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **/

#ifndef PQCLEAN_CROSS_CLEAN_API_H
#define PQCLEAN_CROSS_CLEAN_API_H

#pragma once

#include <stdint.h>

#define PQCLEAN_CROSS_CLEAN_CRYPTO_ALGNAME "CROSS"

// TODO: CRYPTO_SECRETKEYBYTES, CRYPTO_PUBLICKEYBYTES, CRYPTO_BYTES, CRYPTO_RANDOMBYTES

/*  no. of bytes of the secret key */
#define PQCLEAN_CROSS_CLEAN_CRYPTO_SECRETKEYBYTES 32L

/*  no. of bytes of the public key */
#define PQCLEAN_CROSS_CLEAN_CRYPTO_PUBLICKEYBYTES 77L

/* no. of bytes of overhead in a signed message */
#define PQCLEAN_CROSS_CLEAN_CRYPTO_BYTES 12912L //19056L

/* required bytes of input randomness */
#define PQCLEAN_CROSS_CLEAN_CRYPTO_RANDOMBYTES 16L //CROSS library -  parameters.h


int PQCLEAN_CROSS_CLEAN_crypto_sign_keypair(unsigned char *pk,
                        unsigned char *sk
                       );

int PQCLEAN_CROSS_CLEAN_crypto_sign(unsigned char *sm,
                uint64_t *smlen,
                const unsigned char *m,
                uint64_t mlen,
                const unsigned char *sk
               );

int PQCLEAN_CROSS_CLEAN_crypto_sign_open(unsigned char *m,
                     uint64_t *mlen,
                     const unsigned char *sm,
                     uint64_t smlen,
                     const unsigned char *pk
                    );

int PQCLEAN_CROSS_CLEAN_crypto_sign_signature(unsigned char *sig,
                uint64_t *siglen,
                const unsigned char *m,
                uint64_t mlen,
                const unsigned char *sk
               );

int PQCLEAN_CROSS_CLEAN_crypto_sign_verify(const unsigned char *sig,
                uint64_t siglen,
                const unsigned char *m,
                uint64_t mlen,
                const unsigned char *pk
               );

#endif
