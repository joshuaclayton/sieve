# Sieve of Eratosthenes

## A Ruby gem for easy sieving

## Install

Install with Rubygems:

    gem install sieve

## Usage

A method is added to the Numeric class.

    5.sieve  # [2, 3, 5]
    20.sieve # [2, 3, 5, 7, 11, 13, 17]

## Benchmarks

This benchmark loops through a handful of numbers 0 to 1 million in steps of
100000 and runs a sieve on each number.

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
    sieve method    41.430000   0.600000  42.030000 ( 42.261872)
    Numeric#sieve    1.010000   0.250000   1.260000 (  1.342326)

ruby 1.8.7 (2010-08-16 patchlevel 302) [i686-darwin10.4.0]

                        user     system      total        real
    sieve method    41.720000   0.730000  42.450000 ( 43.640117)
    Numeric#sieve    0.960000   0.380000   1.340000 (  1.385924)

ruby 1.8.7 (2010-04-19 patchlevel 253) [i686-darwin10.4.0], MBARI 0x6770, Ruby Enterprise Edition 2010.02

                        user     system      total        real
    sieve method    42.800000   0.910000  43.710000 ( 45.105879)
    Numeric#sieve    1.090000   0.370000   1.460000 (  1.517832)


ruby 1.9.2p0 (2010-08-18 revision 29036) [x86_64-darwin10.4.0]

                        user     system      total        real
    sieve method    22.800000   0.670000  23.470000 ( 24.132390)
    Numeric#sieve    1.000000   0.380000   1.380000 (  1.422877)

## Author

Written by Josh Clayton
