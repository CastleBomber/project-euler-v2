#include "digitCancellingFractions.h"

/**
 * Solves for the four non-trivial fractions
 * that can be simplified by digit cancellation
 * to match their original values
 *
 * trivial fractions: contains 0's that would be used for digit cancellation
 *
 * @return productOfDenominators
 */
int digitCancellingFractions() {
    vector<pair<int, int>> fractions;

    // Iterate through fractions with double digit numbers
    for (int numerator = 11; numerator < 99; numerator++) {
        for (int denominator = numerator + 1; denominator < 99; denominator++) {
            if (isTrivial(numerator, denominator)) {
                continue;
            }
            if (isEqualWithDigitCancel(numerator, denominator)) {
                fractions.emplace_back(numerator, denominator);
            }
        }
    }

    displayFractions(fractions);

    return productOfDenominators(fractions);
}

/**
 * Trivial fractions have 0's on both the top and bottom
 *
 * Function is suited for two-digit numbers
 *
 * @param numerator
 * @param denominator
 * @return bool - true if fraction is trivial
 */
bool isTrivial(int numerator, int denominator) {
    string numStr = to_string(numerator);
    string denStr = to_string(denominator);

    if (numerator == denominator) {
        return true;
    }

    if ((numStr.find('0') != string::npos) &&
        (denStr.find('0') != string::npos)) {
        return true;
    }

    return false;
}

/**
 * Checks if the fraction given is equal to a similiar
 * fraction, which has a matching digit removed from
 * the numerator and denominator
 *
 * @param numerator
 * @param denominator
 * @return bool
 */
bool isEqualWithDigitCancel(int numerator, int denominator) {
    int _n = numerator;
    int _d = denominator;
    int match = findMatchingDigit(numerator, denominator);  // Check if matching digit
    int n2 = 0;                                             // Numerator of second fraction
    int d2 = 0;                                             // Denominator of second fraction

    // If no match found, exit f(x)
    if (match == -1) {
        return false;
    }

    // Remove the matching digit
    n2 = removeMatchingDigit(numerator, match);
    d2 = removeMatchingDigit(denominator, match);

    // Check if the original fraction is equal to the new fraction
    if ((numerator * d2) == (n2 * denominator)) {
        return true;
    }

    // If not equal, return false
    return false;
}

/**
 * Searches for a matching digit from a fraction's
 * numerator and denominator
 *
 * @param numerator
 * @param denominator
 * @return c - '0' - found a matching digit
 *         -1      - matching digit not found
 */
int findMatchingDigit(int numerator, int denominator) {
    string s1 = to_string(numerator);
    string s2 = to_string(denominator);

    for (char c : s1) {
        if (s2.find(c) != string::npos) {
            return c - '0';
        }
    }

    return -1;
}

/**
 * Removes the matching digit that was found from comparing
 * a fraction's numerator with the denominator
 *
 * @param numerator
 * @param denominator
 * @return stoi(numStr) - numerator or denominator with a digit removed
 */
int removeMatchingDigit(int number, int digitToRemove) {
    string numStr = to_string(number);
    char digit = digitToRemove + '0';  // int to char
    size_t pos = numStr.find(digit);

    if (pos != string::npos) {
        numStr.erase(pos, 1);  // Remove one character as pos
    }

    return numStr.empty() ? 0 : stoi(numStr);  // Handle empty case
}

/**
 * Finds the product from a vector of fractions
 * Focuses on the denominator in its lowest common terms
 *
 * @param fractions - four non-trivial double digit special cancelling identity fractions
 * @return f.second - denominator after multiplying the fractions
 */
int productOfDenominators(const vector<pair<int, int>>& fractions) {
    pair<int, int> f = {1, 1};  // Initialize f as 1/1 (identity for multiplication)

    for (const auto& [num, den] : fractions) {
        f.first *= num;
        f.second *= den;
    }

    int _gcd = gcd(f.first, f.second);
    f.first /= _gcd;
    f.second /= _gcd;

    return f.second;
}

void displayFractions(const vector<pair<int, int>>& fractions) {
    cout << "Fractions: ";
    for (auto x : fractions) {
        cout << x.first << "/" << x.second << " ";
    }
    cout << endl;
}