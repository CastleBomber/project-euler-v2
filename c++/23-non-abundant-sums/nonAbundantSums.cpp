#include "nonAbundantSums.h"

/**
 * Finds the sum of all the #'s which
 * cannot be written as the sum of two abundant numbers.
 * The upper limit is set to 28,123.
 *
 * Ex: 1 + .. + 23, 25 + .. + 29, 31 + ..
 * Not: 24 (12+12), 30 (12+18), ..
 *
 * @param
 * @return max
 */
int nonAbundantSums() {
  vector<int> abundantNumbers;
  vector<int> nonAbundantSumNumbers;
  int max = 28123; // Upper limit
  int sum = 0;

  // Find abundant numbers
  abundantNumbers = findAbundantNumbers(max);

  // Find numbers that can't be the sum of abundant numbers
  nonAbundantSumNumbers = findNonAbundantSumNumbers(max, abundantNumbers);

  // Find sum
  sum = sumOfNonAbundantSumNumbers(nonAbundantSumNumbers);

  return sum;
}

/**
 * Finds abundant numbers, which are
 * numbers with proper divisors that add up to be more than itself
 *
 * @param max
 * @return abundantNumbers
 */
vector<int> findAbundantNumbers(int max) {
  vector<int> abundantNumbers;

  for (int x = 0; x < max; x++) {
    if (isAbundant(x)) {
      abundantNumbers.push_back(x);
    }
  }

  return abundantNumbers;
}

/**
 * Determines if a number is a abundant
 *
 * @param number
 * @return result
 */
bool isAbundant(int number) {
  int sum = 0;
  bool result = false;

  // Look for proper divisors
  for (int x = 1; x < number; x++) {
    if (number % x == 0) {
      sum += x;
    }
  }

  // Check if sum is greater than number
  if (sum > number) {
    result = true;
  }

  return result;
}

/**
 * Finds numbers that can't be the sum of abundant numbers
 *
 * @param max
 * @param abundantNumbers
 * @return nonAbundantSumNumbers
 */
vector<int> findNonAbundantSumNumbers(int max, vector<int> abundantNumbers) {
  vector<int> nonAbundantSumNumbers;

  for (int x = 0; x < max; x++) {
    if (!isAbundantSum(x, abundantNumbers)) {
      nonAbundantSumNumbers.push_back(x);
    }
  }

  return nonAbundantSumNumbers;
}

/**
 * Determines if a number is the sum of two abundant numbers
 *
 * @param number
 * @param abundantNumbers
 * @return result
 */
bool isAbundantSum(int number, vector<int> abundantNumbers) {
  bool result = false;

  for (int x = 0; x < abundantNumbers.size(); x++) {
    for (int y = x; y < abundantNumbers.size(); y++) {
      if (abundantNumbers[x] + abundantNumbers[y] == number) {
        result = true;
        return result;
      }
    }
  }

  return result;
}

/**
 * Finds the sum of all the non abundant sum numbers
 *
 * @param nonAbundantSumNumbers
 * @return sum
 */
int sumOfNonAbundantSumNumbers(vector<int> nonAbundantSumNumbers) {
  int sum = 0;

  for (int x = 0; x < nonAbundantSumNumbers.size(); x++) {
    sum += nonAbundantSumNumbers[x];
  }

  return sum;
}