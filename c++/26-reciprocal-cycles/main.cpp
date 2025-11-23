/**
 * Author: CBombs
 * Date: December 22nd, 2024
 *
 * Project Euler: #26 Reciprocal Cycles
 *
 * A unit fraction contains 1 in the numerator. 
 * The decimal representation of the unit fractions 
 * with denominators 2 to 10 are given:
 * 
 * 1/2 = 0.5
 * 1/3 = 0.(3)
 * 1/4 = 0.25
 * 1/5 = 0.2
 * 1/6 = 0.1(6)
 * 1/7 = 0.(142857)
 * 1/8 = 0.125
 * 1/9 = 0.(1)3
 * 1/10 = 0.1
 * 
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
 * It can be seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of for which contains the longest recurring cycle 
 * in its decimal fraction part.
 * 
 * Solution:
 *
 *
 * Acknowledgements:
 *      Denominator with longest recurring cycle: 983
 *      Length of the cycle: 490
 *      Recurring cycle: 0101832993890020366598778004073319755600814663951120162932790224
 *                       0325865580448065173116089613034623217922606924643584521384928716
 *                       9042769857433808553971486761710794297352342158859470468431771894
 *                       0936863543788187372708757637474541751527494908350305498981670061
 *                       0997963340122199592668024439918533604887983706720977596741344195
 *                       5193482688391038696537678207739307535641547861507128309572301425
 *                       6619144602851323828920570264765784114052953156822810590631364562
 *                       118126272912423625254582484725050916496945
 *
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *     **Used long divison techniques that did not rely on these libraries**
 *     GMP (GNU Multiple Precision Arithmetic Library)
 *     For full gmp usage, will need to run:
 *     brew install gmp (Mac)
 *     sudo apt install libgmp-dev (Ubuntu)
 * 
 *     GMP vs Boost.Multiprecision
 *     (older, faster, requires linking c libraries) vs (newer, easier to use, slower)
 */

#include "reciprocalCycles.h"

int main() {
    int maxDenominator = 1000;
    reciprocalCycles(maxDenominator);
    return 0;
}