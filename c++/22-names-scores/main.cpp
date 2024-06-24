/**
 * Author: CBombs
 * Date: May 20th, 2024
 *
 * Project Euler: #22 Names Scores
 *
 * Using names.txt, a text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order.
 * Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name
 * score.
 *
 * For example, when the list is sorted into alphabetical order,COLIN,
 * which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 * So, COLIN would obtain a score of 938 X 53 = 49,714.
 *
 * What is the total of all the name scores in the file?
 *
 * Solution:
 *     Total: 871,198,282
 *
 * Acknowledgements:
 *
 * Replit:
 *     Menu - cmd+j
 *     Code folding - Toggle all folds from menu option

 * Visual Studio Code
 *      Code folding - (cmd+a), cmd+k, cmd+0
 *
 * Debugger:
 *     Breakpoints and for loops require two taps to proceed
 *
 * Notes:
 *
 *
 */

#include "namesScores.h"

int main() {
  string fileName = "names.txt";
  vector<string> names;
  int total = 0;

  // Open file and splice for names
  names = readNamesFromFile(fileName);

  // Solve for alphabetical values and names scores
  total = namesScores(names);

  cout << "Total: " << total << endl;
}