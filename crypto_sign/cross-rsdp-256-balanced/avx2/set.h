
#define RSDP 1
#define CATEGORY_5 1
#define BALANCED 1

#undef NO_TREES

/* When compiling avx2 override the behaviour of architecture_detect.h */
#define IMPLEMENTATION_avx2
#define HIGH_COMPATIBILITY_X86_64
#define HIGH_PERFORMANCE_X86_64

/* Undefine unused macros to facilitate dead code removal using unifdef */

#undef SHA_3_LIBKECCAK

/* Variant */
#undef RSDPG
/* Category */
#undef CATEGORY_1
#undef CATEGORY_2
#undef CATEGORY_3
/* Target */
#undef SPEED
#undef SIG_SIZE
