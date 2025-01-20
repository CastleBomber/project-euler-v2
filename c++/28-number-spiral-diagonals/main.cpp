/**
 * Author: CBombs
 * Date: January 9th, 2025
 *
 * Project Euler: #28 Number Spiral Diagonals
 *
 * Starting with the number 1
 * and moving to the right in a clockwise direction a 5 by 5
 * spiral is formed as follows:
 *      21 22 23 24 25
 *      20  7  8  9 10
 *      19  6  1  2 11
 *      18  5  4  3 12
 *      17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a
 * 1001 by 1001 spiral formed in the same way?
 *
 * Solution:
 *      669,171,001
 *
 * Acknowledgements:
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

#include "numberSpiralDiagonals.h"

int main() {
    int lengthSide = 5;  // Spiral: 1001 x 1001 square

    cout << "The sum of the numbers on the diagonals is: "
         << numberSpiralDiagonals(lengthSide) << endl;

    return 0;
}