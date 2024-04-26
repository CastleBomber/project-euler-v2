/**
 * Author: Richie CastleBomber
 * Date: August 29th, 2023
 *
 * Project Euler: #16 - Power Digit Sum
 *
 * What is the sum of digits of 2^1000?
 *
 * Example:
 * 2^15 = 32,768
 * 3+2+7+6+8 => 26
 *
 * Solution:
 * (Ongoing, needing to use GNU's gmplib for greater precision)
 * (Switching to Python for NumPy and Math libraries to handle large numbers)
 *
 * Notes:
 * GNU Multiprecision Arithmetic Library
 * https://gmplib.org/
 *
 * Replit:
 *   Menu - cmd+j
 *   Code folding - Toggle all folds from menu option
 *
 * Replit seems unable to add tarball libraries (Boost, GMP)
 */

#include "powerDigitSum.h"

int main() {
  string basePower = "2";
  string exponent = "3";
  string binaryString = "";

  // String binarires
  basePower = convertToBinary(stoi(basePower));
  binaryString = basePower;

  // Simulate multiplying by 2 by shifting binary string
  // for (int x = 1; x < stoi(exponent); x++) {
  //   binaryString = shiftByBaseTwo(binaryString);
  // }

  // cout << binaryString << endl;

  int r = (pow(2, 100));
  cout << r << endl;
}
