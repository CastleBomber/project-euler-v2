#include "numberSpiralDiagonals.h"

/**
 * Computes the sum of the numbers on the diagonals
 * 
 * @param lengthSide
 * @return sum
 */
int numberSpiralDiagonals(int lengthSide) {
    vector<int> diagonals;
    int n = 1; 
    int sum = 1; // initial diagonal sum of a 1x1 square
    int sides = 4;
    int jump = 2;  // initial jump

    while (n < pow(lengthSide, 2)) {
        for (int s = 0; s < sides; s++) {
            n += jump;
            sum = sum + n;
        }
        jump += 2;
    }

    return sum;
}
