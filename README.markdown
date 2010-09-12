# Sieve of Eratosthenes

## A Ruby gem for easy sieving

## Install

Install with Rubygems:

    gem install sieve

## Usage

A method is added to the Numeric class.

    5.sieve  # [2, 3, 5]
    20.sieve # [2, 3, 5, 7, 11, 13, 17, 19]

## Benchmarks

This benchmark loops through a handful of numbers 0 to 1 million in steps of
100000 and runs a sieve on each number.  I also include benchmarks for running
the sieve against 10 million.

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

ruby 1.8.6 (2010-02-05 patchlevel 399) [i686-darwin10.4.0]

                          user     system      total        real
    sieve method      41.620000   0.860000  42.480000 ( 42.956830)
    Numeric#sieve      0.360000   0.130000   0.490000 (  0.506452)
    sieve 10_000_000   8.770000   0.110000   8.880000 (  9.019959)
    10_000_000.sieve   0.330000   0.020000   0.350000 (  0.357979)

ruby 1.8.7 (2010-08-16 patchlevel 302) [i686-darwin10.4.0]

                          user     system      total        real
    sieve method      41.180000   0.860000  42.040000 ( 42.246443)
    Numeric#sieve      0.350000   0.130000   0.480000 (  0.479553)
    sieve 10_000_000   8.960000   0.120000   9.080000 (  9.117586)
    10_000_000.sieve   0.340000   0.020000   0.360000 (  0.359590)

ruby 1.8.7 (2010-04-19 patchlevel 253) [i686-darwin10.4.0], MBARI 0x6770, Ruby Enterprise Edition 2010.02

                          user     system      total        real
    sieve method      42.410000   0.750000  43.160000 ( 43.190891)
    Numeric#sieve      0.490000   0.110000   0.600000 (  0.607309)
    sieve 10_000_000   9.040000   0.120000   9.160000 (  9.166911)
    10_000_000.sieve   0.350000   0.020000   0.370000 (  0.371991)

ruby 1.9.2p0 (2010-08-18 revision 29036) [x86_64-darwin10.4.0]

                          user     system      total        real
    sieve method      22.410000   0.800000  23.210000 ( 23.232721)
    Numeric#sieve      0.380000   0.130000   0.510000 (  0.503788)
    sieve 10_000_000   4.820000   0.130000   4.950000 (  4.938275)
    10_000_000.sieve   0.330000   0.030000   0.360000 (  0.353741)

## Author

Written by Josh Clayton
