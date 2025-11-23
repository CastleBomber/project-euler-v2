#ifndef MAIN_H_
#define MAIN_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

void reciprocalCycles(int maxDenominator=1000);
vector<int> getPrimes(int limit);
string recurringCycle(int n);

#endif