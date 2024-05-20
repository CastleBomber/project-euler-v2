#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct AmicablePair {
    int first, second;

    AmicablePair(int _first, int _second) {
        first = _first;
        second = _second;
    }

    /**
     * Equality operator '==', treats (a,b) and (b,a) as same pair
     * Helps avoid duplicate entries
     * Ex: (220,284) and (284,220)
     *
     * @return bool - true if both are same pair
     */
    bool operator==(const AmicablePair &other) const {
        return (first == other.first && second == other.second) ||
               (first == other.second && second == other.first);
    }
};

/**
 * Custom hash function for AmicablePair objects
 * Functor, defines operator() method
 * Bitwise XOR '^'
 * unordered_set requires a hash function
 * unordered_set<AmicablePair, AmicablePairHash> amicablePairs
 * if not provided, compiler will not know how to hash AmicablePair
 *
 * @return size_t
 */
struct AmicablePairHash {
    size_t operator()(const AmicablePair &pair) const {
        // Order independent hash calculation
        return hash<int>()(pair.first) ^ hash<int>()(pair.second);
    }
};

int sumOfProperDivisors(int n);
unordered_set<AmicablePair, AmicablePairHash> findAmicablePairs(int start,
                                                                int end);
int sumOfAmicablePairs(unordered_set<AmicablePair, AmicablePairHash> pairs);

#endif