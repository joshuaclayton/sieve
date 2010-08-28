#include <ruby.h>
#include <math.h>
#include "sieve.h"

void Init_sieve() {
  VALUE rb_mSieve = rb_define_module("Sieve");
  VALUE numeric = rb_define_class("Numeric", rb_cObject);
  rb_define_method(rb_mSieve, "sieve", sieve, 0);
  rb_include_module(numeric, rb_mSieve);
}

VALUE sieve(VALUE self) {
  long number = rb_num2long(self) + 1;
  long *numbers = malloc(number * sizeof(long));

  if(numbers == NULL) { return Qnil; }

  long i;
  for(i = 0; i < number; i++) {
    numbers[i] = i;
  }
  numbers[0] = numbers[1] = -1;

  for(i = 0; i < number; i++) {
    long current_sq = powl(i, 2);
    if(numbers[i] == -1)    { continue; }
    if(current_sq > number) { break; }

    long n;
    for(n = current_sq; n < number; n += i) {
      numbers[n] = -1;
    }
  }

  VALUE primes_array = rb_ary_new();
  for(i = 0; i < number; i++) {
    if(numbers[i] != -1) {
      rb_ary_push(primes_array, LONG2FIX(numbers[i]));
    }
  }

  free(numbers);
  return primes_array;
}
