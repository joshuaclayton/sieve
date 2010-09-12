# Sieve of Eratosthenes

## A Ruby gem for easy sieving

## Install

Install with Rubygems:

    gem install sieve

## Usage

A method is added to the Numeric class.

    >> require "sieve"
    => true
    >> 5.sieve
    => [2, 3, 5]
    >> 100.sieve
    => [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

## Benchmarks

This benchmark loops through a handful of numbers 0 to 1 million in steps of
100000 and runs a sieve on each number.  I also include benchmarks for running
the sieve against 10 million and 100 million.

The sieve method itself looks like this:

    def sieve(n)
      numbers = (0..n).map
      numbers[0] = numbers[1] = nil
      numbers.each do |num|
        next unless num
        break if num**2 > n
        (num**2).step(n, num) {|idx| numbers[idx] = nil }
      end
      numbers.compact
    end

As far as I know, this is the most optimized pure Ruby sieve written.

The benchmarks were run on a 2.8GHz Intel Core 2 Duo MacBook Pro with 8 GB memory.

### ruby 1.8.6 (2010-02-05 patchlevel 399) [i686-darwin10.4.0]

                            user     system      total        real
    sieve method        4.450000   0.060000   4.510000 (  4.526172)
    Numeric#sieve       0.040000   0.000000   0.040000 (  0.046676)
    sieve 10_000_000    8.780000   0.120000   8.900000 (  9.010072)
    10_000_000.sieve    0.080000   0.000000   0.080000 (  0.084518)
    100_000_000.sieve   2.050000   0.050000   2.100000 (  2.128403)

### ruby 1.8.7 (2010-08-16 patchlevel 302) [i686-darwin10.4.0]

                            user     system      total        real
    sieve method        4.460000   0.060000   4.520000 (  4.522069)
    Numeric#sieve       0.040000   0.000000   0.040000 (  0.046349)
    sieve 10_000_000    8.820000   0.120000   8.940000 (  8.955888)
    10_000_000.sieve    0.080000   0.010000   0.090000 (  0.083030)
    100_000_000.sieve   2.040000   0.040000   2.080000 (  2.100103)

### ruby 1.8.7 (2010-04-19 patchlevel 253) [i686-darwin10.4.0], MBARI 0x6770, Ruby Enterprise Edition 2010.02

                            user     system      total        real
    sieve method        4.610000   0.090000   4.700000 (  4.730966)
    Numeric#sieve       0.050000   0.010000   0.060000 (  0.046442)
    sieve 10_000_000    8.640000   0.060000   8.700000 (  8.731662)
    10_000_000.sieve    0.100000   0.000000   0.100000 (  0.104731)
    100_000_000.sieve   2.250000   0.050000   2.300000 (  2.303147)

### ruby 1.9.2p0 (2010-08-18 revision 29036) [x86_64-darwin10.4.0]

                            user     system      total        real
    sieve method        2.410000   0.060000   2.470000 (  2.468430)
    Numeric#sieve       0.050000   0.000000   0.050000 (  0.049053)
    sieve 10_000_000    4.770000   0.110000   4.880000 (  4.888397)
    10_000_000.sieve    0.080000   0.000000   0.080000 (  0.098229)
    100_000_000.sieve   2.090000   0.040000   2.130000 (  2.137024)

## Author

Written by Josh Clayton
