#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int digitFifthPowers(int power);
int setUpperLimit(int power);
vector<int> setMatchingNumbers(int upperLimit, int power);
int sumDigitsToPower(int num, int power);
int sumVector(vector<int> numbers);

#endif