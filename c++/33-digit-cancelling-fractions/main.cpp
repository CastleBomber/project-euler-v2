/**
 * Author: CBombs
 * Date: April 11th, 2025
 *
 * Project Euler: #33 Digit Cancelling Fractions
 *
 * The fraction 49/98 is a curious fraction,
 * as an inexperienced mathematician in attempting to
 * simplify it may incorrectly believe that 49/98 = 4/8,
 * which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction,
 * less than one in value, and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator.
 *
 * Solution:
 *      Fractions: 16/64 19/95 26/65 49/98 
 *      Denominator from product: 100
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
 *
 */

#include "digitCancellingFractions.h"

int main() {
    int sum = digitCancellingFractions();

    cout << "Denominator from product: " << sum << endl;

    return 0;
}