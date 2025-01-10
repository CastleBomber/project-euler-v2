/**
 * Author: CBombs
 * Date: December 30th, 2024
 *
 * Project Euler: #27 Quadratic Primes
 *
 * Euler discovered the remarkable quadratic formula:
 * n^2 + n + 41
 * It turns out that the formula will produce primes for the
 * consecutive integer values 0 <= n <= 39.
 * However, when n = 40,
 * 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41,
 * and certainly when n = 41,
 * 41^2 + 41 + 41 is clearly divisible by 41.
 *
 * The incredible formula n^2 - 79n + 1601 was discovered, which produces 80
 * primes for the consecutive values 0 <= n <= 79.
 * The product of the coefficients, -79 and 1601, is -126,479.
 *
 * Considering quadratics of the form:
 * n^2 + an + b, where |a| < 1000 and |b| <= 1000
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |-4| = 4
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 *
 *
 * Solution:
 *      n^2 - 61n + 971
 *      a: -61, b: 971, numPrimes: 71
 *      Multiplicand, a*b = -59231
 *
 * Acknowledgements:
 *      ChatGPT, help with SieveOfEratosthenes and prime functions
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

#include "quadraticPrimes.h"

int main() {
    int limit = 1000;  // Max values of coefficients

    quadraticPrimes(limit);

    return 0;
}