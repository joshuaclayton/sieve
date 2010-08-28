Gem::Specification.new do |s|
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.3.7}

  s.name = %q{sieve}
  s.summary = %q{Sieve of Eratosthenes}
  s.homepage = %q{http://github.com/joshuaclayton/sieve}
  s.version = "0.0.1"
  s.authors = ["Josh Clayton"]
  s.date = %q{2010-08-28}
  s.email = %q{joshua.clayton@gmail.com}
  s.extensions = ["ext/sieve/extconf.rb"]
  s.files = [
    ".gitignore",
    "MIT-LICENSE",
    "README.markdown",
    "Rakefile",
    "benchmark.rb",
    "lib/sieve.rb",
    "ext/sieve/extconf.rb",
    "ext/sieve/sieve.c",
    "ext/sieve/sieve.h",
  ]
  s.test_files = [
    "cucumber.yml",
    "features/sieve.feature",
    "features/step_definitions/sieve_steps.rb",
    "features/support/env.rb",
    "features/support/primes.txt"
  ]
end
