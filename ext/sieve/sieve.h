#ifndef __sieve_h__
#define __sieve_h__
static VALUE sieve(VALUE);

typedef struct {
  long* numbers;
  long start;
  long end;
  long step;
} param;

#endif
