#include "reciprocalCycles.h"

/**
 *
*/
void reciprocalCycles() {
    mpf_set_default_prec(5000); // Set precision to 5000 bits (~1500 digits)
    mpf_class a("1.1234567890123456789012345678901234567890");
    mpf_class b("2.9876543210987654321098765432109876543210");

    mpf_class result = a * b;
    
    cout << result << endl;

    gmp_printf("%.9Ff\n", result.get_mpf_t());

    // Build a factorials list
    factorial(1000);
    
    // For loop from 1 to 1000
    // Calculate 1/n
    // Store decimal representation in a string
    // Find the recurring cycle 
    // Keep track of the longest cycle and its corresponding n
    // Output the result
}

/**
 * Factorial function that handles large numbers
 * Uses Boost's cpp_int
 * 
 * @param n - number
 * @return result - factorial of n
 */
void factorial(int n) {
    vector<mpz_class> factorials(1001);
    factorials[0] = 1;  // 0! = 1

    for (int i = 1; i <= 1000; ++i){
        factorials[i] = factorials[i - 1] * i;
    }

    // Prints first 10 and 1000!
    for (int i = 1; i <= 10; ++i) {
        cout << i << "! = " << factorials[i] << endl;
    }
}
