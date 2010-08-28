Feature: Sieve of Eratosthenes
  In order to kick ass at finding primes
  As a developer
  I should be able to call a sieve on a numeric to find its primes

  Scenario Outline: Find primes effectively
    When I calculate the sieve for <number>
    Then I should have the primes <primes>
    Examples:
      | number | primes                                                                                 |
      | -12345 | nil                                                                                    |
      | -5     | nil                                                                                    |
      | -1     | nil                                                                                    |
      | 0      |                                                                                        |
      | 1      |                                                                                        |
      | 2      | 2                                                                                      |
      | 3      | 2,3                                                                                    |
      | 4      | 2,3                                                                                    |
      | 5      | 2,3,5                                                                                  |
      | 19     | 2,3,5,7,11,13,17,19                                                                    |
      | 20     | 2,3,5,7,11,13,17,19                                                                    |
      | 29     | 2,3,5,7,11,13,17,19,23,29                                                              |
      | 30     | 2,3,5,7,11,13,17,19,23,29                                                              |
      | 110    | 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109 |

  Scenario: Allocating memory for the sieve raises an exception if it fails
    When I calculate the sieve for 1000000000000000000
    Then a NoMemoryError should be raised

  Scenario: Prime tables
    When I load all the primes from "features/support/primes.txt"
    And I calculate the sieve for the last number
    Then I should have all primes from "features/support/primes.txt"
