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
  short* numbers = malloc(number * sizeof(short));

  if(numbers == NULL) {
    rb_raise(rb_eNoMemError, "Can't allocate enough memory.");
  }

  numbers[0] = numbers[1] = 0;
  long i;
  for(i = 2; i < number; i++) { numbers[i] = 1; }

  long current_square;
  for(i = 0; i < number; i++) {
    if(numbers[i] == 0) { continue; }

    current_square = powl(i, 2);
    if(current_square > number) { break; }

    long n;
    for(n = current_square; n < number; n += i) {
      numbers[n] = 0;
    }
  }

  VALUE primes_array = rb_ary_new();
  for(i = 0; i < number; i++) {
    if(numbers[i] == 1) {
      rb_ary_push(primes_array, LONG2FIX(i));
    }
  }

  free(numbers);

  return primes_array;
}
