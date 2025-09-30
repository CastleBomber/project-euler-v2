#include "digitFactorials.h"

/**
 * 
 */
void digitFactorials() {
    int smallest = 0;
    int largest = 0;
    int maxDigits = maximumDigits();

    // for (int i = 0; i < maxDigits; i++) {
    smallest = maxDigits * (int)factorial(9);
    largest = pow(10,maxDigits-1);
    // } 

    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
}

/**
 * n*9!
 * Maximum number made with respect to the rules
 * that remains less than the smallest n-digit number from
 * 10^(n-1)
 * 
 * Comparing the two equations
 * to find when the length of a number 
 * surpasses a factorial product, with respect to n
 * 
 * ex:
 *        n*9!    < 10^(n-1)
 * n=1: 362,880   < 1 (false)
 * n=2: 725,760   < 10 (false)
 * n=3: 1,088,640 < 100 (false)
 * ...
 * n=7: 2,540,160 < 1,000,000 (false)
 * n=8: 2,903,040 < 10,000,000 (true)
 * 
 * @return int maximum number of digits
 */
int maximumDigits() {
    for (int n = 1; n < 10; n++) {
        // The length of the number finally surpasses the factorial product
        if ((n * factorial(9)) < (10^(n-1))) {
            return n-1;
        }
    }

    return 0;
}

/**
 * 
 */
boost::multiprecision::cpp_int factorial(unsigned int n) {
    cpp_int result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

