#include "digitFifthPowers.h"

/**
 *
 * @param
 * @return
 */
int digitFifthPowers(int power) {
    int upperLimit = setUpperLimit(power);

    auto matchingNumbers = setMatchingNumbers(upperLimit, power);

    return sumVector(matchingNumbers);
}

/**
 * Finds the upper limit of the sum of the Xth power of their digits
 * compares the larget possible sum with the smallest n-digit number possible
 * and returns the number of digits when n-digit number exceeds what the sum
 * can possibly equate to
 *
 * @param power - raised power of digit summation
 * @return upperLimit
 */
int setUpperLimit(int power) {
    int largestPossibleSum;
    int smallestNDigitNumber;
    int digitMaxPower = pow(9, power);
    int n = 1;

    do {
        largestPossibleSum = n * digitMaxPower;
        smallestNDigitNumber = pow(10, (n - 1));
        n++;
    } while (largestPossibleSum > smallestNDigitNumber);

    // The previous largestPossibleSum before breaking the valid limit
    int upperLimit = (n - 2) * digitMaxPower;  

    return upperLimit;
}

vector<int> setMatchingNumbers(int upperLimit, int power) {
    vector<int> matchingNumbers{};

    for (int num = 2; num <= upperLimit; num++) {
        int sumOfDigits = sumDigitsToPower(num, power);

        if (num == sumOfDigits) {
            matchingNumbers.push_back(num);
        }
    }

    for (auto x : matchingNumbers) {
        cout << "Match: " << x << endl;
    }

    return matchingNumbers;
}

int sumDigitsToPower(int num, int power) {
    int sumOfDigits = 0;

    for (auto digit : to_string(num)) {
        sumOfDigits += pow(digit - '0',power);  // char to int
    }

    return sumOfDigits;
}

int sumVector(vector<int> numbers) {
    int sum = 0;

    for (auto num : numbers) {
        sum += num;
    }

    return sum;
}