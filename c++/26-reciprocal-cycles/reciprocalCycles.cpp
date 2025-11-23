#include "reciprocalCycles.h"

/**
 * Find the denominator with the longest recurring cycle in its decimal fraction part
 * 
 * Fractions with prime denominators can have the longest recurring cycles
 * 
 * @param maxDenominator - The maximum denominator to check for recurring cycles
 * @return void - Prints the denominator with the longest recurring cycle, the cycle itself, and its length
*/
void reciprocalCycles(int maxDenominator) {
    // Build a primes list
    vector<int> primes = getPrimes(maxDenominator);
    
    // Find the denominator with the longest recurring cycle 
    vector<pair<int, string>> cycles;
    int longestLength = 0;
    int denomWithLongestCycle = 0;
    for (auto prime : primes) {
        int tmpLength = recurringCycle(prime).size();

        if (tmpLength > longestLength) {
            longestLength = tmpLength;
            denomWithLongestCycle = prime;
        }
    }

    cout << "Denominator with longest recurring cycle: " << denomWithLongestCycle << endl;
    cout << "Length of the cycle: " << recurringCycle(longestLength).size() << endl;
    cout << "Recurring cycle: " << recurringCycle(longestLength) << endl;
}

/**
 * Sieve of Eratosthenes to get all primes up to limit
 * 
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
