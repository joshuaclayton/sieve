#ifndef __sieve_h__
#define __sieve_h__

#define BITSET(x,i)    ((x)[(i)>>3] &  (1<<((i)&7))) != 0
#define BITNOTSET(x,i) ((x)[(i)>>3] &  (1<<((i)&7))) == 0
#define SETBIT(x,i)    ((x)[(i)>>3] |= (1<<((i)&7)))
#define CLEARBIT(x,i)  ((x)[(i)>>3] &= (1<<((i)&7))^0xFF)

typedef struct {
  char* results;
  long  number;
} sieve_data;

static VALUE sieve(VALUE);

static sieve_data* initialize_sieve_data(const VALUE);
static void destroy_sieve_data(sieve_data*);
static void default_sieve_data(sieve_data*);
static void initialize_results(sieve_data*);
static void remove_non_primes(sieve_data*);
static VALUE primes_array_from_sieve_data(sieve_data*);
static void ensure_memory_allocated(void*);

#endif
