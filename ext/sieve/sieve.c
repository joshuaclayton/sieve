#include <ruby.h>
#include <math.h>
#include "sieve.h"

void Init_sieve() {
  VALUE rb_mSieve = rb_define_module("Sieve"),
        numeric   = rb_define_class("Numeric", rb_cObject);
  rb_define_method(rb_mSieve, "sieve", sieve, 0);
  rb_include_module(numeric, rb_mSieve);
}

static VALUE sieve(const VALUE self) {
  if(NUM2LONG(self) < 2) { return Qnil; }
  long number = NUM2LONG(self) + 1;

  char* results = malloc((long)(number/8));

  if(results == NULL) {
    rb_raise(rb_eNoMemError, "Can't allocate enough memory.");
  }

  CLEARBIT(results, 0);
  CLEARBIT(results, 1);
  long i;
  for(i = 2; i < number; i++) { SETBIT(results, i); }

  long current_square;
  for(i = 0; i < number; i++) {
    if(BITNOTSET(results, i)) { continue; }

    current_square = powl(i, 2);
    if(current_square > number) { break; }

    long n;
    for(n = current_square; n < number; n += i) { CLEARBIT(results, n); }
  }

  VALUE primes_array = rb_ary_new();
  for(i = 0; i < number; i++) {
    if(BITSET(results, i)) { rb_ary_push(primes_array, LONG2FIX(i)); }
  }

  free(results);

  return primes_array;
}
