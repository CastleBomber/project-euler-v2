/**
 * Author: CBombs
 * Date: September 19th, 2023
 *
 * Project Euler: #18 Maximum Path Sum I
 *
 * By starting at the top of the triangle and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *
 *      3
 *     7 4
 *    2 4 6
 *   8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23
 * Find the maximum total from top to bottom of the given triangle.txt
 *
 * Solution:
 *  1074
 *
 * Notes:
 *  Bottom Up approach eliminates paths
 *  Dynamic Programming
 *  Tree Data Structure
 *  Depth First Search, traversals: 1) Inorder, 2) Preorder, 3) Postorder
 *  Breadth First Search
 *
 * Replit:
 *   Menu - cmd+j
 *   Code folding - Toggle all folds from menu option
 *
 */
#include "maximumPathSum.h"

int main() {
  int maxTotal = 0;
  vector<vector<int>> matrix;

  // Open file and load in triagle
  string fileName = "triangle.txt";
  matrix = getMatrixFromFile(matrix, fileName);

  // Solve for highest valued path
  maxTotal = maxPath(matrix);

  //testMatrix(matrix);

  cout << maxTotal << endl;
}
