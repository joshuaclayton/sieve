# -*- encoding: utf-8 -*-
lib = File.expand_path("../lib/", __FILE__)
$:.unshift(lib) unless $:.include?(lib)

require "sieve/version"

Gem::Specification.new do |s|
  s.name             = %q{sieve}
  s.summary          = %q{Sieve of Eratosthenes}
  s.description      = %q{Ruby C Extension for the Sieve of Eratosthenes}
  s.homepage         = %q{http://github.com/joshuaclayton/sieve}
  s.version          = Sieve::VERSION
  s.authors          = ["Josh Clayton"]
  s.email            = %q{joshua.clayton@gmail.com}

  s.require_paths = ["lib"]
  s.extensions = ["ext/sieve/extconf.rb"]
  s.files      = %x{git ls-files}.split("\n").reject {|file| file =~ /^(features|cucumber)/ }
  s.test_files = %x{git ls-files}.split("\n").select {|file| file =~ /^(features|cucumber)/ }

  s.add_dependency "rake-compiler",        "0.7.9"
  s.add_development_dependency "rspec",    "2.7.0"
  s.add_development_dependency "cucumber", "1.1.0"
end
