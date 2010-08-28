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

Ruby 1.8.7p253 REE 2010.02

                        user     system      total        real
    sieve method    32.820000   0.710000  33.530000 ( 33.727176)
    Numeric#sieve    1.040000   0.420000   1.460000 (  1.476743)

Ruby 1.9.2p0

                        user     system      total        real
    sieve method    21.460000   0.620000  22.080000 ( 22.170883)
    Numeric#sieve    0.940000   0.320000   1.260000 (  1.262891)

## Author

Written by Josh Clayton
