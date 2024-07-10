////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//   DUMMY PARALLEL KECCAK (JUST THE SERIAL VERSION CALLED 4 TIMES)
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#pragma once

#include "fips202.h"

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#define shake128x4incctx my_par_keccak_128_context
#define shake128x4_inc_init keccak_128_x4_init
#define shake128x4_inc_absorb keccak_128_x4_absorb
#define shake128x4_inc_finalize keccak_128_x4_finalize
#define shake128x4_inc_squeeze(o1,o2,o3,o4,ol,s) keccak_128_x4_squeeze(s,o1,o2,o3,o4,ol)
#define shake128x4_inc_ctx_release keccak_128_x4_release

#define shake256x4incctx my_par_keccak_256_context
#define shake256x4_inc_init keccak_256_x4_init
#define shake256x4_inc_absorb keccak_256_x4_absorb
#define shake256x4_inc_finalize keccak_256_x4_finalize
#define shake256x4_inc_squeeze(o1,o2,o3,o4,ol,s) keccak_256_x4_squeeze(s,o1,o2,o3,o4,ol)
#define shake256x4_inc_ctx_release keccak_256_x4_release

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

typedef struct {
    shake128incctx s1;
    shake128incctx s2;
    shake128incctx s3;
    shake128incctx s4;
} my_par_keccak_128_context;

////////////////////////////////////////////////////////////////////////

static inline void keccak_128_x4_init(my_par_keccak_128_context *ctx);
static inline void keccak_128_x4_absorb(my_par_keccak_128_context *ctx, const unsigned char *in1, const unsigned char *in2, const unsigned char *in3, const unsigned char *in4, unsigned int in_len);
static inline void keccak_128_x4_finalize(my_par_keccak_128_context *ctx);
static inline void keccak_128_x4_squeeze(my_par_keccak_128_context *ctx, unsigned char *out1, unsigned char *out2, unsigned char *out3, unsigned char *out4, unsigned int out_len);
static inline void keccak_128_x4_release(my_par_keccak_128_context *ctx);

////////////////////////////////////////////////////////////////////////

static inline void keccak_128_x4_init(my_par_keccak_128_context *ctx){
    shake128_inc_init(&ctx->s1);
    shake128_inc_init(&ctx->s2);
    shake128_inc_init(&ctx->s3);
    shake128_inc_init(&ctx->s4);
}
static inline void keccak_128_x4_absorb(my_par_keccak_128_context *ctx, const unsigned char *in1, const unsigned char *in2, const unsigned char *in3, const unsigned char *in4, unsigned int in_len){
    shake128_inc_absorb(&ctx->s1, in1, in_len);
    shake128_inc_absorb(&ctx->s2, in2, in_len);
    shake128_inc_absorb(&ctx->s3, in3, in_len);
    shake128_inc_absorb(&ctx->s4, in4, in_len);
}
static inline void keccak_128_x4_finalize(my_par_keccak_128_context *ctx){
    shake128_inc_finalize(&ctx->s1);
    shake128_inc_finalize(&ctx->s2);
    shake128_inc_finalize(&ctx->s3);
    shake128_inc_finalize(&ctx->s4);
}
static inline void keccak_128_x4_squeeze(my_par_keccak_128_context *ctx, unsigned char *out1, unsigned char *out2, unsigned char *out3, unsigned char *out4, unsigned int out_len){
    shake128_inc_squeeze(out1, out_len, &ctx->s1);
    shake128_inc_squeeze(out2, out_len, &ctx->s2);
    shake128_inc_squeeze(out3, out_len, &ctx->s3);
    shake128_inc_squeeze(out4, out_len, &ctx->s4);
}
static inline void keccak_128_x4_release(my_par_keccak_128_context *ctx){
    shake128_inc_ctx_release(&ctx->s1);
    shake128_inc_ctx_release(&ctx->s2);
    shake128_inc_ctx_release(&ctx->s3);
    shake128_inc_ctx_release(&ctx->s4);
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

typedef struct {
    shake256incctx s1;
    shake256incctx s2;
    shake256incctx s3;
    shake256incctx s4;
} my_par_keccak_256_context;

////////////////////////////////////////////////////////////////////////

static inline void keccak_256_x4_init(my_par_keccak_256_context *ctx);
static inline void keccak_256_x4_absorb(my_par_keccak_256_context *ctx, const unsigned char *in1, const unsigned char *in2, const unsigned char *in3, const unsigned char *in4, unsigned int in_len);
static inline void keccak_256_x4_finalize(my_par_keccak_256_context *ctx);
static inline void keccak_256_x4_squeeze(my_par_keccak_256_context *ctx, unsigned char *out1, unsigned char *out2, unsigned char *out3, unsigned char *out4, unsigned int out_len);
static inline void keccak_256_x4_release(my_par_keccak_256_context *ctx);

////////////////////////////////////////////////////////////////////////

static inline void keccak_256_x4_init(my_par_keccak_256_context *ctx){
    shake256_inc_init(&ctx->s1);
    shake256_inc_init(&ctx->s2);
    shake256_inc_init(&ctx->s3);
    shake256_inc_init(&ctx->s4);
}
static inline void keccak_256_x4_absorb(my_par_keccak_256_context *ctx, const unsigned char *in1, const unsigned char *in2, const unsigned char *in3, const unsigned char *in4, unsigned int in_len){
    shake256_inc_absorb(&ctx->s1, in1, in_len);
    shake256_inc_absorb(&ctx->s2, in2, in_len);
    shake256_inc_absorb(&ctx->s3, in3, in_len);
    shake256_inc_absorb(&ctx->s4, in4, in_len);
}
static inline void keccak_256_x4_finalize(my_par_keccak_256_context *ctx){
    shake256_inc_finalize(&ctx->s1);
    shake256_inc_finalize(&ctx->s2);
    shake256_inc_finalize(&ctx->s3);
    shake256_inc_finalize(&ctx->s4);
}
static inline void keccak_256_x4_squeeze(my_par_keccak_256_context *ctx, unsigned char *out1, unsigned char *out2, unsigned char *out3, unsigned char *out4, unsigned int out_len){
    shake256_inc_squeeze(out1, out_len, &ctx->s1);
    shake256_inc_squeeze(out2, out_len, &ctx->s2);
    shake256_inc_squeeze(out3, out_len, &ctx->s3);
    shake256_inc_squeeze(out4, out_len, &ctx->s4);
}
static inline void keccak_256_x4_release(my_par_keccak_256_context *ctx){
    shake256_inc_ctx_release(&ctx->s1);
    shake256_inc_ctx_release(&ctx->s2);
    shake256_inc_ctx_release(&ctx->s3);
    shake256_inc_ctx_release(&ctx->s4);
}

////////////////////////////////////////////////////////////////////////

