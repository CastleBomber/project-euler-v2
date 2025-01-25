#include "distinctPowers.h"

/**
 * Counts the distinct terms are in the sequence generated by
 * a^b for
 * lowerLimit <= a <= upperLimit and
 * lowerLimit <= b <= upperLimit
 *
 * @param lowerLimit
 * @return upperLimit
 */
int distinctPowers(int lowerLimit, int upperLimit) {
    vector<mpz_class> terms;
    int count = 0;

    for (int a = lowerLimit; a <= upperLimit; a++) {
        for (int b = lowerLimit; b <= upperLimit; b++) {
            mpz_class result;
            mpz_pow_ui(result.get_mpz_t(), mpz_class(a).get_mpz_t(), b);
            terms.push_back(result);
        }
    }

    removeDuplicates(terms);
    count = terms.size();

    return count;
}

/**
 * Removes power duplicates
 * Unsorted order approach, O(n)
 *
 * @param terms
 */
void removeDuplicates(vector<mpz_class>& terms) {
    unordered_set<string> uniqueSet;
    for (const auto& term : terms) {
        uniqueSet.insert(term.get_str());  // Convert mpz_class to string
    }

    terms.clear();
    for (const auto& strTerm : uniqueSet) {
        terms.push_back(mpz_class(strTerm));  // Convert back to mpz_class
    }
}
