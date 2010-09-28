$LOAD_PATH << File.join(File.dirname(__FILE__), "lib")
require "sieve"

Gem::Specification.new do |s|
  s.name             = %q{sieve}
  s.summary          = %q{Sieve of Eratosthenes}
  s.description      = %q{Ruby C Extension for the Sieve of Eratosthenes}
  s.homepage         = %q{http://github.com/joshuaclayton/sieve}
  s.version          = Sieve::VERSION
  s.authors          = ["Josh Clayton"]
  s.email            = %q{joshua.clayton@gmail.com}

  s.rubygems_version = %q{1.3.7}
  s.date             = %q{2010-09-12}

  s.require_paths = ["lib"]
  s.extensions = ["ext/sieve/extconf.rb"]
  s.files      = %x{git ls-files}.split("\n").reject {|file| file =~ /^(features|cucumber)/ }
  s.test_files = %x{git ls-files}.split("\n").select {|file| file =~ /^(features|cucumber)/ }
end

