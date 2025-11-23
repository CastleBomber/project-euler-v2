#include "reciprocalCycles.h"

/**
 *
*/
void reciprocalCycles(int maxDenominator) {
    mpf_set_default_prec(5000); // Set precision to 5000 bits (~1500 digits)

    // Build a primes list
    vector<int> primes = getPrimes(maxDenominator);
       
    // Calculate 1/n for each prime
    // vector<mpf_class> decimals;
    // for (auto n : primes) {
    //     decimals.push_back(mpf_class(1)/n);
    // }
    
    // Find the denominator with the longest recurring cycle 
    vector<pair<int, string>> cycles;
    int denominatorWithLongestLength = 0;
    for (auto prime : primes) {
        int tmpLength = recurringCycle(prime).size();

        if (tmpLength > denominatorWithLongestLength) {
            denominatorWithLongestLength = tmpLength;
        }
    }

    // Output the result
    cout << "Denominator with longest recurring cycle: " << denominatorWithLongestLength << endl;
    cout << "Recurring cycle: " << recurringCycle(denominatorWithLongestLength) << endl;
    cout << "Length of the cycle: " << recurringCycle(denominatorWithLongestLength).size() << endl;
}

/**
 * Sieve of Eratosthenes to get all primes up to limit
 * @param limit - The upper limit to find primes
 * @return primes - A vector of prime numbers up to limit
*/
vector<int> getPrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(limit); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

/**
 * Find the recurring cycle in the decimal representation of 1/n
 * 
 * Once a remainder repeats, the recurring cycle is found
 * 
 * @param n - The denominator to find the recurring cycle for 1/n
 * @return cycle - The recurring cycle in the decimal representation of 1/n
*/
string recurringCycle(int n) {
    unordered_map<int, int> seenRemainders;  // stores the computed remainders and their positions
    vector<int> digits;
    int remainder = 1 % n;
    int pos = 0;

    while (remainder != 0 && !seenRemainders.count(remainder)) {
        seenRemainders[remainder] = pos;

        remainder *= 10;
        int digit = remainder / n;
        digits.push_back(digit);

        remainder = remainder % n;
        pos++;
    }

    if (remainder == 0) return "";  // terminates, no cycle

    // Find where the cycle starts in the digits
    int start = seenRemainders[remainder];
    string cycle;
    for (int i = start; i < digits.size(); i++) {
        cycle += char('0' + digits[i]); // convert the int to a char, so we can add it to the cycle string
    }   

    return cycle;
}
