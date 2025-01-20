#ifndef MAIN_H_
#define MAIN_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Triple {
    int a;
    int b;
    int numPrimes;
};

int quadraticPrimes(int limit);
vector<int> sieveOfEratosthenes(int n);
vector<int> setValues(int aMin, int aMax);
Triple setEquation(vector<int> primes, vector<int> potentialAs);
int getNumberOfPrimes(int a, int b);
bool isPrime(int n);
int calcuateMultiplicandOfCoeffecients(Triple equation);

#endif