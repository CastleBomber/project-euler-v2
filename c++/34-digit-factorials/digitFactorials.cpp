#include "digitFactorials.h"

/**
 * Finds the sum of all numbers which are equal to the sum of the factorial of their digits
 * Uses the equation:  n*9! < 10^(n-1)  to limit the search space
 */
void digitFactorials() {
    vector<int> nums = getFactorials();
    
    cout << "Sum: " << getSum(nums) << endl;
}

/**
 * 
 * 
 */
vector<int> getFactorials() {
    vector<int> nums;
    cpp_int largestPossibleNumber = pow(cpp_int(10), maximumDigits()-1); // 10^(n-1)
    
    for (int num = 3; num < largestPossibleNumber; num++) {
        int sum = 0;

        for (int i = 0; i < numDigits(num); i++) {
            string numStr = to_string(num);
            sum += (int)factorial(numStr[i] - '0');
            
            if (sum == num) {
                nums.push_back(num);
            }
        }
    }

    return nums;
}

/**
 * n*9!
 * Maximum number made with respect to the problem's rules
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
 * n=7: 2,540,160 < 1,000,000 (false) *
 * n=8: 2,903,040 < 10,000,000 (true)
 * 
 * @return int maximum number of digits
 */
int maximumDigits() {
    for (int n = 1; n < 10; n++) {
        cpp_int left = n * factorial(9);
        cpp_int right = pow(cpp_int(10), n-1); // Use's Boost's pow()
        
        // The length of the number finally surpasses the factorial product
        if (left < right) {
            return n-1;
        }
    }

    return 0;
}

/**
 * Factorial function that handles large numbers
 * Uses Boost's cpp_int
 * 
 * @param n - number
 * @return result - factorial of n
 */
cpp_int factorial(unsigned int n) {
    cpp_int result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/**
 * Calcuate the number of decimal digits in a specific integer value
 * 
 * @param n - number
 * @return number of characters within n
 */
int numDigits(int n) {
    if (n == 0) return 1;
    return static_cast<int>(log10(abs(n))) + 1;
}

/**
 * Finds the sum of all integers within a vector
 * 
 * @param nums - vector of factorials that meet the problem's criteria
 * @return sum - sum of all integers within nums
 */
int getSum(vector<int> nums) {
    int sum = 0;
    
    for (int num : nums) {
        sum += num;
    }
    
    return sum;
}
