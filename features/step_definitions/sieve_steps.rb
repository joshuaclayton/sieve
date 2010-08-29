When /^I calculate the sieve for (\-?\d+)$/ do |number|
  begin
    @result = number.to_i.sieve
  rescue Exception => @sieve_exception
  end
end

Then /^I should have the primes (.*)$/ do |primes|
  case primes
  when "nil"
    @result.should be_nil
  else
    @primes = primes.split(",").map {|prime| prime.to_i }
    @result.should == @primes
  end
end

When /^I load all the primes from "([^"]*)"$/ do |path|
  @primes = prime_file_process(path)
  @primes.should_not be_empty
end

When /^I calculate the sieve for the last number$/ do
  When %{I calculate the sieve for #{@primes.last}}
end

Then /^I should have all primes from "([^"]*)"$/ do |path|
  Then %{I should have the primes #{prime_file_process(path).join(",")}}
end

Then /^a NoMemoryError should be raised$/ do
  @sieve_exception.should be_a(NoMemoryError)
end

module PrimeFileProcessor
  def prime_file_process(path)
    @processed_cache ||= {}

    if @processed_cache[path]
      @processed_cache[path]
    else
      @processed_cache[path] = File.new(path).read.strip.split(/\s+/).map {|prime| prime.to_i }
    end
  end
end

World(PrimeFileProcessor)
