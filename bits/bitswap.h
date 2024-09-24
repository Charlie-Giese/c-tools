#include <stdlib.h>
#include "bitsperlong.h"

static inline unsigned long bit_swap_1(unsigned long x)
// Return x with neighbour bits swapped
{
#if BITS_PER_LONG == 32
    unsigned long m = 0x55555555UL;
#else
#if BITS_PER_LONG == 64
    unsigned long m = 0x5555555555555555UL;
#endif
#endif
    return ((x & m) << 1) | ((x & (~m)) >> 1);
}

static inline unsigned long bit_swap_2(unsigned long x)
// Return x with pairs of bits swapped
{
#if BITS_PER_LONG == 32
    unsigned long m = 0x33333333UL;
#else
#if BITS_PER_LONG == 64
    unsigned long m = 0x3333333333333333UL;
#endif
#endif
    return ((x & m) << 2) | ((x & (~m)) >> 2);
}

static inline unsigned long bit_swap_4(unsigned long x)
// Return x with groups of 4 bits swapped.
{
#if BITS_PER_LONG == 32
    unsigned long m = 0x0f0f0f0fUL;
#else
#if BITS_PER_LONG == 64
    unsigned long m = 0x0f0f0f0f0f0f0f0fUL;
#endif
#endif
    return ((x & m) << 4) | ((x & (~m)) >> 4);
}

static inline unsigned long bit_swap_8(unsigned long x)
// Return x with groups of 8 bits swapped.
{
#if BITS_PER_LONG == 32
    unsigned long m = 0x00ff00ffUL;
#else
#if BITS_PER_LONG == 64
    unsigned long m = 0x00ff00ff00ff00ffUL;
#endif
#endif
    return ((x & m) << 8) | ((x & (~m)) >> 8);
}

static inline unsigned long bit_swap_16(unsigned long x)
// Return x with groups of 16 bits swapped.
{
#if BITS_PER_LONG == 32
    unsigned long m = 0x0000ffffUL;
#else
#if BITS_PER_LONG == 64
    unsigned long m = 0x0000ffff0000ffffUL;
#endif
#endif
    return ((x & m) << 16) | ((x & (m<<16)) >> 16);
}

static inline unsigned long bit_swap_32(unsigned long x)
// Return x with groups of 32 bits swapped (for 64-bit arch)
{
    unsigned long m = 0x00000000ffffffffUL;
    return ((x & m) << 32) | ((x & (m<<32)) >> 32);
}



