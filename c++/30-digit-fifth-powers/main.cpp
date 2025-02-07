/**
 * Author: CBombs
 * Date: January 25th, 2025
 *
 * Project Euler: #30 Digit Fifth Powers
 *
 * Surprisingly there are only three numbers that can be written as 
 * the sum of fourth powers of their digits:
 * 
 * 1634 = 1⁴ + 6⁴ + 3⁴ + 4⁴, 
 * 8208 = 8⁴ + 2⁴ + 0⁴ + 8⁴, 
 * 9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴.
 * 
 * As 1 = 1⁴ is not a sum it is not included.
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * 
 * Find the sum of all the numbers that can be written as 
 * the sum of fifth powers of their digits.
 *
 * Solution:
 *      Sum of fifth powers of their digits: 443,839
 *
 * Acknowledgements:
 *      
 * 
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *      Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *
 */

#include "digitFifthPowers.h"

int main() {
    int power = 5;
    int sum = digitFifthPowers(power);

    cout << "Answer: " << sum << endl;

    return 0;
}