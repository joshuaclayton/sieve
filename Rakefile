require "rubygems"
require "rake"
require "benchmark"

require "rake/extensiontask"
Rake::ExtensionTask.new("sieve") do |extension|
  extension.lib_dir = "lib/sieve"
end

task :build => [:clean, :compile]

require "cucumber/rake/task"
Cucumber::Rake::Task.new(:cucumber => :build)

task :default => :cucumber

desc "Benchmark C implementation against pure Ruby implementation of the Sieve"
task(:benchmark => :build) do
  $LOAD_PATH.unshift(File.join(File.dirname(__FILE__), "lib"))
  require "sieve"

  def sieve(n)
    numbers = (0..n).map {|i| i }
    numbers[0] = numbers[1] = nil
    numbers.each do |num|
      next unless num
      break if num**2 > n
      (num**2).step(n, num) {|idx| numbers[idx] = nil }
    end
    numbers.compact
  end

  Benchmark.bmbm(15) do |benchmark|
    range = (0..1000000)
    step = 100000

    benchmark.report("sieve method") do
      range.step(step) do |i|
        sieve(i)
      end
    end

    benchmark.report("Numeric#sieve") do
      range.step(step) do |i|
        i.sieve
      end
    end

    benchmark.report("sieve 10_000_000") do
      sieve 10_000_000
    end

    benchmark.report("10_000_000.sieve") do
      10_000_000.sieve
    end

    benchmark.report("100_000_000.sieve") do
      100_000_000.sieve
    end
  end
end
