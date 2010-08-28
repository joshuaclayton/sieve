#!/usr/bin/env ruby

require "rubygems"
require "benchmark"
require "sieve"

def sieve(n)
  numbers = (0..n).map(&:to_i)
  numbers[0] = numbers[1] = nil
  numbers.each do |num|
    next unless num
    break if num**2 > n
    (num**2).step(n, num) {|idx| numbers[idx] = nil }
  end
  numbers.compact
end

Benchmark.bm(15) do |benchmark|
  range = (0..1000000)
  step = 10000
  benchmark.report("sieve method") do
    range.step(step).each do |i|
      sieve(i)
    end
  end

  benchmark.report("Numeric#sieve") do
    range.step(step).each do |i|
      i.sieve
    end
  end
end
