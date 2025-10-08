#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/integer.hpp> // For pow()

using namespace std;
using boost::multiprecision::cpp_int;

void digitFactorials();
vector<int> getFactorials();
int maximumDigits();
cpp_int factorial(unsigned int n);
int numDigits(int n);
int getSum(vector<int> nums);

#endif