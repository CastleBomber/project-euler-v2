#include "lexicographicPermutations.h"

/**
 * Finds the specified position in the lexicographic permutation
 *
 * Ex: The lexicographic permutations of [0,1,2] are:
 * 012   021   102   120   201   210
 *
 * @param digits
 * @param targetIndex
 * @return permutation
 */
vector<int> lexicographicPermutations(vector<int> digits, int targetIndex) {
    vector<int> permutation;

    // Order the digits
    sort(digits.begin(), digits.end());

    // Find the specific permutation
    permutation = findPermutation(digits, targetIndex);

    return permutation;
}

/**
 * Find the specific permutation from given digits
 *
 * @param digits
 * @param targetIndex
 * @return permutation
 */
vector<int> findPermutation(vector<int> digits, int targetIndex) {
    vector<int> permutation;
    targetIndex -= 1;
    int n = digits.size();

    while (!digits.empty()) {
        int factorial = findFactorial(n - 1);
        int groupIndex = targetIndex / factorial;
        permutation.push_back(digits[groupIndex]);
        digits.erase(digits.begin() + groupIndex);
        targetIndex %= factorial;
        n -= 1;
    }

    return permutation;
}

int findFactorial(int n) {
    // Base case: 0! = 1! = 1
    if (n <= 1) {
        return 1;
    }

    return n * findFactorial(n - 1);
}

void displayResults(const vector<int>& permutation) {
    for (auto x : permutation) {
        cout << x << " ";
    }
    cout << endl;
}