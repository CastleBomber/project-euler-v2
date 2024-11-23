#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int nonAbundantSums();
vector<int> findAbundantNumbers(int max);
bool isAbundant(int number);
vector<int> findNonAbundantSumNumbers(int max, vector<int> abundantNumbers);
bool isAbundantSum(int number, vector<int> abundantNumbers);
int sumOfNonAbundantSumNumbers(vector<int> nonAbundantSumNumbers);

#endif