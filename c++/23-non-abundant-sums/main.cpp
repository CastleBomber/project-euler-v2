/**
 * Author: CBombs
 * Date: June 24th, 2024
 *
 * Project Euler: #23 Non-Abundant Sums
 *
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number.
 *
 * For example, the sum of the proper divisors of 28 would be
 * 1 + 2 + 4 + 7 + 14 = 28,
 * which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n
 * and is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant #, 
 * A(12) = 1 + 2 + 3 + 4 + 6 = 16, 
 * the smallest # that can be written as the sum of two abundant #'s is 24 (12+12).
 *
 * By mathematical analysis, it can be shown that all integers >28,123
 * can be written as the sum of two abundant #'s.
 *
 * However, this upper limit cannot be reduced any further by analysis even
 * though it is known that the greatest number that cannot be expressed as
 * the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which 
 * cannot be written as the sum of two abundant numbers.
 *
 * Solution:
 *  NonAbundantSum: 4,179,871
 *
 * Acknowledgements:
 *  Replit AI
 *
 * Replit:
 *     Menu - cmd+j
 *     Code folding - Toggle all folds from menu option

 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *    Deficient - Perfect - Abundant
 *    # vs sum-of-divisors  (#)
 *    Proper Divisor - positive divisor other than the number itself
 *
 */

#include "nonAbundantSums.h"

int main() {
  int sum = 0;

  // Finds the sum of numbers that cannot be the sum of abundant numbers
  sum = nonAbundantSums();

  cout << "NonAbundantSum: " << sum << endl;
}