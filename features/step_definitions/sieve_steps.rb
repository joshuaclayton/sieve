When /^I run a sieve on (\d+)$/ do |number|
  @result = number.to_i.sieve
end

Then /^I should have the primes (.*)$/ do |primes|
  @primes = primes.split(",").map(&:strip).map(&:to_i)
  @result.should == @primes
end

When /^I load all the primes from "([^"]*)"$/ do |path|
  @primes = prime_file_process(path)
  @primes.should_not be_empty
end

When /^I run a sieve on the last number$/ do
  @result = @primes.last.sieve
end

Then /^I should have all primes from "([^"]*)"$/ do |path|
  Then %{I should have the primes #{prime_file_process(path).join(",")}}
end

module PrimeFileProcessor
  def prime_file_process(path)
    File.new(path).read.strip.split(/\s+/).map(&:to_i)
  end
end

World(PrimeFileProcessor)
