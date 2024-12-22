#include "1000digitFibonacciNumber.h"

/**
 * Compute the fibonacci sequence until the element with the
 * desired number of digits is found
 *
 * @param numDigits - number of digits of searched value
 * @return index - position in fibonacci sequence with number containing specified number of digits
 */
int xDigitFibonacciNumber(int numDigits) {
    mpz_class Fn = 1;
    mpz_class prev2 = 0;
    int index = 1;

    // Compute fibonacci sequence, check if number of digits is met
    while (Fn.get_str(10).length() < numDigits) {
        mpz_class prev1 = Fn;
        Fn = prev1 + prev2;
        prev2 = prev1;
        index++;
    }

    return index;
}
