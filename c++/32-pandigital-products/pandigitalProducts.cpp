#include "pandigitalProducts.h"

/**
 * Finds the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 *
 * Equations:
 * A * B = C
 *
 * a + b + c = 9
 *
 * Two number length formulas from multiplication:
 * (a + b = c)
 * (a + b - 1 = c)
 *
 * Ex:
 * 99 * 999 = 98,901  => (a + b = c)  => 2,3 -> 5
 * 10 * 10 = 100  => (a + b - 1 = c)  => 2,2 -> 3
 *
 * First formula:
 * (a + b = c)
 * a + b + (c) = 9
 * a + b + (a + b) = 9
 * 2a + 2b ≠ 9
 * Invalid
 *
 * Second formula:
 * (a + b - 1 = c)
 * a + b + (c) = 9
 * a + b + (a + b - 1) = 9
 * 2a + 2b = 10
 * a + b = 5
 * Valid
 *
 * Therefore,
 * a = 2, b = 3 or
 * a = 1, b = 4
 *
 * @return sumProducts(products) -  sum of all the products
 */
int pandigitalProducts() {
    set<int> products = {};

    int min1Digit = 2;
    int max1Digit = 9;
    int min4Digits = 1234;
    int max4Digits = 9876;

    // a = 1 digit, b = 4 digits
    for (int a = min1Digit; a < max1Digit; a++) {
        for (int b = min4Digits; b < max4Digits; b++) {
            int c = a * b;
            string concatenatedStr = to_string(a) + to_string(b) + to_string(c);

            if (isPandigital(concatenatedStr)) {
                products.insert(c);
            }
        }
    }

    int min2Digits = 12;
    int max2Digits = 98;
    int min3Digits = 123;
    int max3Digits = 987;

    // a = 2 digits, b = 3 digits
    for (int a = min2Digits; a < max2Digits; a++) {
        for (int b = min3Digits; b < max3Digits; b++) {
            int c = a * b;
            string concatenatedStr = to_string(a) + to_string(b) + to_string(c);

            if (isPandigital(concatenatedStr)) {
                products.insert(c);
            }
        }
    }

    return sumProducts(products);
}

/**
 * Checks if the given string is pandigital from 1 to 9
 * Handles duplicate numbers
 *
 * @return true - string is panditial
 * @return false - string is not pandigital
 */
bool isPandigital(string concatenatedStr) {
    set<int> pandigitalSet = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (char c : concatenatedStr) {
        int number = c - '0';

        // If it does not exist in set, may be a duplicate, hence not pandigital
        if (!pandigitalSet.erase(number)) {
            return false;
        }
    }

    if (pandigitalSet.empty()) {
        return true;
    }

    return false;
}

int sumProducts(set<int> products) {
    int sum = 0;

    for (const auto& x : products) {
        sum += x;
    }

    return sum;
}
