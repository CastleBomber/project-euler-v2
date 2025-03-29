/**
 * Author: CBombs
 * Date: May 5th, 2025
 * 
 * Project Euler: #32 Pandigital Sums
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 
 * 1 to n exactly once; 
 * for example, 
 * the 5-digit number, 15234, is 1 through 5 pandigital.
 * 
 * The product 7254 is unusual, as the identity, 39 x 186 = 7254, 
 * containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 * 
 * Find the sum of all products whose multiplicand/multiplier/product identity 
 * can be written as a 1 through 9 pandigital.
 * 
 * HINT: Some products can be obtained in more than one way 
 * so be sure to only include it once in your sum.
 *
 * Solution:
 *      Attempt: 45228
 *
 * Acknowledgements:
 *      DeepSeek
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

#include "pandigitalProducts.h"

int main() {
    
    int sum = pandigitalProducts();

    cout << "Sum of pandigital products: " << sum << endl;

    return 0;
}