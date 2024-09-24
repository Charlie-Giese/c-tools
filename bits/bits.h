#include <stdlib.h>
#include <stdbool.h>
#include "bitswap.h"

#define BITS_PER_LONG 64

static inline unsigned long average(unsigned long x, unsigned long y) 
// Return floor ( (x+y)/2 )
// Use:         x+y == ((x&y)<<1) + (x^y)
// that is:     sum == carries    + sum_without_carries
{
    return (x & y) + ((x ^ y) >> 1);
}

static inline unsigned long ceil_average(unsigned long x, unsigned long y)
// Use: x+y == ((x|y)<<1) - (x^y)
// ceil_average(x,y) == average(x,y) + ((x^y)&1))
{
    return (x | y) - ((x ^ y) >> 1);
}

// Functions for finding next even/odd number
static inline unsigned long next_even(unsigned long x) { return (x|1)+1; }
static inline unsigned long prev_even(unsigned long x) { return (x-1)&~1; }

static inline unsigned long next_odd(unsigned long x) { return (x+1)|1; }
static inline unsigned long prev_odd(unsigned long x) { return (x&~1)-1; }

//functions for finding next even/odd number, but return x if x is even/odd
static inline unsigned long next0_even(unsigned long x) { return (x+1)&~1; }
static inline unsigned long prev0_even(unsigned long x) { return x&~1; }

static inline unsigned long next0_odd(unsigned long x) { return x|1; }
static inline unsigned long prev0_odd(unsigned long x) { return (x-1)|1; }

static inline unsigned long test_bit(unsigned long a, unsigned long i)
// Return zero if bit[i] is zero,
// else return one-bit word with bit[i] set.
{
    return (a & (1UL << i));
}
static inline bool test_bit01(unsigned long a, unsigned long i)
// Return whether bit[i] is set.
{
    return ( 0 != test_bit(a, i) );
}
static inline unsigned long set_bit(unsigned long a, unsigned long i)
// Return a with bit[i] set.
{
    return (a | (1UL << i));
}
static inline unsigned long clear_bit(unsigned long a, unsigned long i)
// Return a with bit[i] cleared.
{
    return (a & ~(1UL << i));
}
static inline unsigned long change_bit(unsigned long a, unsigned long i)
    // Return a with bit[i] toggled.
{
    return (a ^ (1UL << i));
}

static inline unsigned long bit_swap(unsigned long a, unsigned long k1, unsigned long k2)
// Return a with bits at positions [k1] and [k2] swapped.
// k1==k2 is allowed (a is unchanged then)
{
    unsigned long x = ((a>>k1) ^ (a>>k2)) & 1; // one if bits differ
    a ^= (x<<k2); // change if bits differ
    a ^= (x<<k1); // change if bits differ
    return a;
}

static inline unsigned long bitrev(unsigned long x)
// Return x with reversed bit order
{
    x = bit_swap_1(x);
    x = bit_swap_2(x);
    x = bit_swap_4(x);
    x = bit_swap_8(x);
    x = bit_swap_16(x);
#if BITS_PER_LONG >= 64
    x = bit_swap_32(x);
#endif
    return x;
}