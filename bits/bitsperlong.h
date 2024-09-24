//If GNU, check for arch, otherwise default to 64-bit

#if __GNUC__
#if __x86_64__ || __ppc64__
#define BITS_PER_LONG 64
#else
#define BITS_PER_LONG 32
#endif
#else
#define BITS_PER_LONG 64
#endif