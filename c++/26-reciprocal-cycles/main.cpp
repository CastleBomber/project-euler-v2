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
 *
 *
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
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
    // mpf_set_default_prec(5000); // Set precision to 5000 bits (~1500 digits)
    // mpf_class a("1.1234567890123456789012345678901234567890");
    // mpf_class b("2.9876543210987654321098765432109876543210");

    // mpf_class result = a * b;
    
    // cout << result << endl;

    reciprocalCycles();

    return 0;
}