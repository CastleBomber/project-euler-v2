/**
 * Author: CBombs
 * Date: Febuary 6th, 2025
 *
 * Project Euler: #31 Coin Sums
 *
 * In the United Kingdom the currency is made up of pound (£) and pence (p).
 * There are eight coins in general circulation:
 *
 *      1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p)
 *
 * It is possible to make £2 in the following way:
 *
 *      1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 * How many different ways can £2 be made using any number of coins?
 *
 * Solution:
 *      Total number of combinations to make £2: 73,682
 *
 * Acknowledgements:
 *      DeepSeek
 *      Understanding Project Euler #31, answer by Zobayer
 *      https://stackoverflow.com/questions/790606/understanding-project-euler-31
 *      Project Euler Problem 31 Solution Coin Sums, article by BetaProjects
 *      https://betaprojects.com/solutions/project-euler/project-euler-problem-031-solution/
 *
 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *      Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *      Dynamic Programming
 *      breaking the problem into smaller subproblems,
 *      store intermediate results, avoid redundant calculations
 *
 */

#include "coinSums.h"

int main() {
    int target = 200;  // 200p = £2
    int combinations = coinSums(target);

    cout << "Total number of combinations to make £2: " << combinations << endl;

    return 0;
}