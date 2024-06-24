/**
 * Author: CBombs
 * Date: October 16th, 2023
 *
 * Project Euler: #21 Amicable Numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n
 * (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair
 * and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are:
 * {1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110};
 * so, d(220) = 284.
 *
 * The proper divisors of 284 are:
 * {1, 2, 4, 71 and 142};
 * so, d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10,000.
 *
 * Solution:
 *     A(<10,000) = ({,}, {220, 284}, {,})
 *     Sum(A(<1000)) = 31,626
 *
 * Acknowledgements:
 *     Open AI's Chat GPT
 *
 * Replit:
 *     Menu - cmd+j
 *     Code folding - Toggle all folds from menu option
 *
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *     amicable numbers - pairs of numbers,
 *     where they each are the sum of all the proper divisors for given number,
 *     (excluding iteself); d(n) = {..+..}
 *     Perfect Numbers are not amicable numbers (unique pairs), ex: (6,6)
 *
 */

#include "amicableNumbers.h"

int main() {
    unordered_set<AmicablePair, AmicablePairHash> amicablePairs;
    int start = 0;
    int end = 10000;
    int sumOfPairs = 0;

    // Find amicable pairs
    amicablePairs = findAmicablePairs(start, end);

    // Add up all the amicable pairs under the max
    sumOfPairs = sumOfAmicablePairs(amicablePairs);

    return 0;
}