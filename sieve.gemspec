$LOAD_PATH << File.join(File.dirname(__FILE__), "lib")
require "sieve"

Gem::Specification.new do |s|
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.3.7}

  s.name = %q{sieve}
  s.summary = %q{Sieve of Eratosthenes}
  s.description = %q{Ruby C Extension for the Sieve of Eratosthenes}
  s.homepage = %q{http://github.com/joshuaclayton/sieve}
  s.version = Sieve::VERSION
  s.authors = ["Josh Clayton"]
  s.date = %q{2010-09-12}
  s.email = %q{joshua.clayton@gmail.com}
  s.extensions = ["ext/sieve/extconf.rb"]
  s.files = [
    ".gitignore",
    "MIT-LICENSE",
    "README.markdown",
    "Rakefile",
    "ext/sieve/extconf.rb",
    "ext/sieve/sieve.c",
    "ext/sieve/sieve.h",
    "lib/sieve.rb"
  ]
  s.test_files = [
    "cucumber.yml",
    "features/sieve.feature",
    "features/step_definitions/sieve_steps.rb",
    "features/support/env.rb",
    "features/support/primes.txt"
  ]
end

