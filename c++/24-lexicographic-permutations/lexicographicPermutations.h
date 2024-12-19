#ifndef MAIN_H_
#define MAIN_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> lexicographicPermutations(vector<int> digits, int targetIndex);
vector<int> findPermutation(vector<int> digits, int targetIndex);
int findFactorial(int n);
void displayResults(const vector<int>& permutation);

#endif