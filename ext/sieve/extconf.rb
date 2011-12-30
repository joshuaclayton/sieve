require "mkmf"
$CFLAGS = "--std=c99 -O"
create_makefile("sieve/sieve")
