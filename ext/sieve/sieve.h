#ifndef __sieve_h__
#define __sieve_h__

#define BITSET(x,i)    ((x)[(i)>>3] &  (1<<((i)&7))) != 0
#define BITNOTSET(x,i) ((x)[(i)>>3] &  (1<<((i)&7))) == 0
#define SETBIT(x,i)    ((x)[(i)>>3] |= (1<<((i)&7)))
#define CLEARBIT(x,i)  ((x)[(i)>>3] &= (1<<((i)&7))^0xFF)

static VALUE sieve(VALUE);
#endif
