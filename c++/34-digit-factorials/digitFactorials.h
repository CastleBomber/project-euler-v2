#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

void digitFactorials();
int maximumDigits();
cpp_int factorial(unsigned int n);

#endif