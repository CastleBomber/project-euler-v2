#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int digitCancellingFractions();
bool isTrivial(int numerator, int denominator);
bool isEqualWithDigitCancel(int numerator, int denominator);
int findMatchingDigit(int numerator, int denominator);
int removeMatchingDigit(int number, int digitToRemove);
int productOfDenominators(const vector<pair<int, int>>& fractions);
void displayFractions(const vector<pair<int, int>>& fractions);

#endif