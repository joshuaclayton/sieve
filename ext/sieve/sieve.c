#include <ruby.h>
#include <math.h>
#include <pthread.h>
#include "sieve.h"

void Init_sieve() {
  VALUE rb_mSieve = rb_define_module("Sieve"),
        numeric   = rb_define_class("Numeric", rb_cObject);
  rb_define_method(rb_mSieve, "sieve", sieve, 0);
  rb_include_module(numeric, rb_mSieve);
}

static void* clear_numbers(void* arg) {
  param* params = (param *)arg;
  long n;
  for(n = params->start; n < params->end; n += params->step) {
    params->numbers[n] = -1;
  }
}

static VALUE sieve(const VALUE self) {
  if(NUM2LONG(self) < 0) { return Qnil; }
  long number = NUM2LONG(self) + 1,
     * numbers = malloc(number * sizeof(long));

  if(numbers == NULL) {
    rb_raise(rb_eNoMemError, "Can't allocate enough memory.");
  }

  long i;
  for(i = 0; i < number; i++) {
    numbers[i] = i;
  }
  numbers[0] = numbers[1] = -1;

  long thread_count = 5;

  long current_square;
  pthread_t* threads = malloc(thread_count * sizeof(pthread_t));
  param* params = malloc(thread_count * sizeof(param));

  for(i = 0; i < number; i += thread_count) {
    int broken = 0;
    long thread_incr, thread_incr_stop = -1;

    for(thread_incr = 0; thread_incr < thread_count; thread_incr++) {
      long current_i = thread_incr + i;
      current_square = powl(current_i, 2);

      if(numbers[current_i] == -1) { continue; }
      if(current_square > number) {
        broken = 1;
        thread_incr_stop = thread_incr;
        break;
      }

      params[thread_incr].numbers = numbers;
      params[thread_incr].start   = current_square;
      params[thread_incr].end     = number;
      params[thread_incr].step    = current_i;

      pthread_create(&threads[thread_incr],
                     NULL,
                     clear_numbers, (void *)(params + thread_incr));
    }

    for(thread_incr = 0; thread_incr < (thread_incr_stop > -1 ? thread_incr_stop : thread_count); thread_incr++) {
      pthread_join(threads[thread_incr], NULL);
    }

    if(broken == 1) { break; } // bubble break
  }

  free(threads);
  free(params);

  VALUE primes_array = rb_ary_new();
  for(i = 0; i < number; i++) {
    if(numbers[i] != -1) {
      rb_ary_push(primes_array, LONG2FIX(numbers[i]));
    }
  }

  free(numbers);

  return primes_array;
}
