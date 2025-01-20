#include "quadraticPrimes.h"

/**
 * Find the quadratic equation that produces the greatest amount of prime numbers
 * under the specified parameters
 *
 * n^2 + an + b,
 * where |a| < 1000 and |b| <= 1000
 *
 * b must be prime, since starting with n = 0
 * prime numbers must be positive, > 1
 *
 * @param limit
 * @return result
 */
int quadraticPrimes(int limit) {
    vector<int> primes;       // b coefficient
    vector<int> potentialAs;  // a coefficient
    int aMin = -limit;
    int aMax = limit;
    Triple equation;
    int result;

    // Find prime numbers
    primes = sieveOfEratosthenes(limit);

    // Find suitable leading 'a' coefficient under 1,000 (+ or -)
    potentialAs = setValues(aMin, aMax);

    // Calculate number of primes produced
    equation = setEquation(primes, potentialAs);

    // Multiply coefficients from set with the greatest number of primes
    result = calcuateMultiplicandOfCoeffecients(equation);

    cout << "Equation, a: " << equation.a << ", b: " << equation.b << ", numPrimes: " << equation.numPrimes << endl;
    cout << "Result of a*b coffecients = " << result << endl;

    return result;
}

/**
 * Prime numbers generator algorithm
 * @param n
 * @return primes
 */
vector<int> sieveOfEratosthenes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);  // Deals with computational search
    isPrime[0] = isPrime[1] = false;    // 0 and 1 are not prime

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

/**
 * Simply loads up a vector with sequential digits
 * specified by the parameters
 *
 * @param aMin
 * @param aMax
 * @return x
 */
vector<int> setValues(int aMin, int aMax) {
    vector<int> potentialAs;

    for (int i = aMin; i <= aMax; i++) {
        potentialAs.push_back(i);
    }

    return potentialAs;
}

/**
 *
 * @param
 * @param
 * @return
 */
Triple setEquation(vector<int> primes, vector<int> potentialAs) {
    Triple equation = {0, 0, 0};
    int curPrimesCount = 0;

    for (int p = 0; p < primes.size(); p++) {
        for (int i = 0; i < potentialAs.size(); i++) {
            curPrimesCount = getNumberOfPrimes(potentialAs[i], primes[p]);
            if (curPrimesCount > equation.numPrimes) {
                equation.a = potentialAs[i];
                equation.b = primes[p];
                equation.numPrimes = curPrimesCount;
            }
        }
    }

    return equation;
}

/**
 * n^2 + an + b
 *
 * starting with n = 0,
 * product the maxiumum number of primes for
 * consecutive values of n
 *
 * @param a
 * @param b
 * @return
 */
int getNumberOfPrimes(int a, int b) {
    int numOfPrimes = 0;
    int n = 0;
    int value = 0;
    bool wasPrime = false;

    do {
        value = pow(n, 2) + (a * n) + b;
        wasPrime = isPrime(value);
        if (wasPrime) {
            numOfPrimes++;
        }
        n++;
    } while (wasPrime);

    return numOfPrimes;
}

bool isPrime(int n) {
    // 0 and 1 are not prime
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;  // Found a divisor
        }
    }

    return true;  // Prime
}

int calcuateMultiplicandOfCoeffecients(Triple equation) {
    int result = 0;

    result = equation.a * equation.b;

    return result;
}
