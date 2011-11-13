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
  if(NUM2LONG(self) < 2) { return rb_ary_new(); }

  sieve_data* data = initialize_sieve_data(self);

  default_sieve_data(data);
  remove_non_primes(data);
  VALUE primes_array = primes_array_from_sieve_data(data);

  destroy_sieve_data(data);

  return primes_array;
}

static sieve_data* initialize_sieve_data(const VALUE self) {
  sieve_data* data = (sieve_data*)malloc(sizeof(sieve_data));

  data->number  = NUM2LONG(self) + 1;
  data->results = malloc((long)(data->number/8));

  ensure_memory_allocated(data->results);

  return data;
}

static void remove_non_primes(sieve_data* data) {
  long current_square, i, n;

  for(i = 0; i < data->number; i++) {
    if(BITNOTSET(data->results, i)) { continue; }

    current_square = powl(i, 2);
    if(current_square > data->number) { break; }

    for(n = current_square; n < data->number; n += i) { CLEARBIT(data->results, n); }
  }

  return;
}

static void default_sieve_data(sieve_data* data) {
  CLEARBIT(data->results, 0);
  CLEARBIT(data->results, 1);

  long i;
  for(i = 2; i < data->number; i++) { SETBIT(data->results, i); }
  return;
}

static VALUE primes_array_from_sieve_data(sieve_data* data) {
  VALUE primes_array = rb_ary_new();

  long i;
  for(i = 0; i < data->number; i++) {
    if(BITSET(data->results, i)) { rb_ary_push(primes_array, LONG2FIX(i)); }
  }

  return primes_array;
}

static void ensure_memory_allocated(void* data) {
  if(NULL == data) {
    rb_raise(rb_eNoMemError, "Can't allocate enough memory.");
  }
}

static void destroy_sieve_data(sieve_data* data) {
  free(data->results);
  free(data);
  return;
}
