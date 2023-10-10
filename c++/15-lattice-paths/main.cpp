/**
 * Author: CBombs
 * Date: AUG 28th, 2023
 *
 * Project Euler: #15 Lattice Paths
 *
 * Starting in the top left corner of a 2x2 grid,
 * and only being able to move to the right and down,
 * there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20x20 grid?
 *
 * Shortcuts:
 *  VS Code:
 * 	    c++ VS Code clang-formatter: shift+alt+f
 *
 * Solution #1:
 *  Discrete Math - 137,846,528,820
 *  C++ using doubles - 1.37847e+11 (needs precision)
 *
 * Solution #2:
 *  C++ with memoization - (ongoing)
 *
 * Replit:
 *   Menu - cmd+j
 *   Code folding - Toggle all folds from menu option
 *
 */

#include "latticePaths.h"

int main(void) {
  int gridSideLength = 20; // 20x20 grid
  double routes = 0;       // # of traversible possibilites

  routes = discreteMathSolution(gridSideLength);

  cout << routes << endl;

  return 0;
}