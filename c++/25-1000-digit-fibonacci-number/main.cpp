/**
 * Author: CBombs
 * Date: December 20th, 2024
 *
 * Project Euler: #25 1000-digit Fibonacci Number
 *
 * The Fibonacci sequence is defined by the recurrence relation:
 * F(n) = F(n-1) + F(n-2), where F(1) = 1 and F(2) = 1.
 *
 * Hence the first terms will be:
 *      F(1) = 1
 *      F(2) = 1
 *      F(3) = 2
 *      F(4) = 3
 *      F(5) = 5
 *      F(6) = 8
 *      F(7) = 13
 *      F(8) = 21
 *      F(9) = 34
 *      F(10) = 55
 *      F(11) = 89
 *      F(12) = 144
 *
 * The 12th term, F(12), is the first term to contain three digits.
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 *
 * Solution:
 *
 *
 * Acknowledgements:
 *
 *
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *     Base cases:
 *     F(0) = 0
 *     F(1) = 1
 */

#include "1000digitFibonacciNumber.h"

int main() {
    int numDigits = 1000;
    int result = 0;

    result = xDigitFibonacciNumber(numDigits);

    cout << result << endl;
}