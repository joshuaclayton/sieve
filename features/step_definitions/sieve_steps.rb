When /^I run a sieve on (\-?\d+)$/ do |number|
  begin
    @result = number.to_i.sieve
  rescue Exception => @sieve_exception
  end
end

Then /^I should have the primes (.*)$/ do |primes|
  case primes
  when "nil"
    @result.should be_nil
  when ""
    @result.should be_empty
  else
    @primes = primes.split(",").map(&:strip).map(&:to_i)
    @result.should == @primes
  end
end

When /^I load all the primes from "([^"]*)"$/ do |path|
  @primes = prime_file_process(path)
  @primes.should_not be_empty
end

When /^I run a sieve on the last number$/ do
  When %{I run a sieve on #{@primes.last}}
end

Then /^I should have all primes from "([^"]*)"$/ do |path|
  Then %{I should have the primes #{prime_file_process(path).join(",")}}
end

Then /^a NoMemoryError should be raised$/ do
  @sieve_exception.should be_a(NoMemoryError)
end

module PrimeFileProcessor
  def prime_file_process(path)
    File.new(path).read.strip.split(/\s+/).map(&:to_i)
  end
end

World(PrimeFileProcessor)
