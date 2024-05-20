#include "amicableNumbers.h"

using namespace std;

// Finds the sum of all the divisors of a given number
int sumOfProperDivisors(int n) {
    int sum = 1;

    // Efficient because any factor larger than sqrt(n) will be a factor of n
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            sum += i;

            // Avoid duplicate additions to sum
            if (n / i != i) {
                sum += n / i;
            }
        }
    }

    return sum;
}

/**
 * Finds all the amicable pairs under the given range
 *
 * Perfect numbers are NOT amicable numbers
 * They would NOT create an true distinct amicable pair
 * EX: 6 is perfect, but not amicable
 * EX: 28 is perfect, but not amicable
 *
 * @param start - The lower bound of the range
 * @param end - The upper bound of the range
 * @return - A vector of all the amicable pairs under the given range
 */
unordered_set<AmicablePair, AmicablePairHash> findAmicablePairs(int start,
                                                                int end) {
    unordered_set<AmicablePair, AmicablePairHash> amicablePairs;
    unordered_map<int, int> divisors_sum;  // Serves as a Cache, Memoization
    int sum1 = 0;                          // Holds sum of divisors from num
    int sum2 = 0;                          // Holds sum of divisors from sum1

    for (int num = start; num < end; num++) {
        // If num (key) is not in cache
        if (divisors_sum.find(num) == divisors_sum.end()) {
            // Store the key and result into the cache
            sum1 = sumOfProperDivisors(num);
            divisors_sum[num] = sum1;
        } else {
            // Used cache value
            sum1 = divisors_sum[num];
        }

        // If sum1 (key) is not in the cache
        if (divisors_sum.find(sum1) == divisors_sum.end()) {
            // Store the key and result into the cache
            sum2 = sumOfProperDivisors(sum1);
            divisors_sum[sum1] = sum2;
        } else {
            // Use cached value
            sum2 = divisors_sum[sum1];
        }

        // Amicable vs Perfect numbers
        if (num == sum2 && num != sum1) {
            amicablePairs.insert(AmicablePair(num, sum1));
        }
    }

    return amicablePairs;
}

// Sums all the amicable pairs
int sumOfAmicablePairs(unordered_set<AmicablePair, AmicablePairHash> pairs) {
    int sum = 0;

    for (auto x : pairs) {
        cout << x.first << " " << x.second << endl;
        sum += x.first + x.second;
    }

    cout << sum << endl;

    return sum;
}