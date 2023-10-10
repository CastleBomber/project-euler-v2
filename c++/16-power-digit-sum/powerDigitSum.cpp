#include "powerDigitSum.h"

/**
 * Early on, we convert the starting numbers to binary
 * and keep them that way throughout the calculations
 *
 * @param number - base power
 * @return binary - binary representation of given number
 */
string convertToBinary(unsigned int number) {
  string result = "";

  while (number != 0) {
    result = (number % 2 == 0 ? "0" : "1") + result;
    number = number / 2;
  }

  return result;
}

/**
 * Shifts over original binary string to mimic
 * multiplying by 2
 * Pass by reference
 *
 * @param &number - address of original binary string
 * @return result - number with an appended 0
 */
string shiftByBaseTwo(string &number) {
  string result = "";
    
  result = number;

  result.push_back('0');

  return result;
}

/**
 * Adds up all the digits from a given binary string
 *
 * @param number - binary string
 * @return result - sum of all the digits
 */
string sumOfDigits(string number) {
  string result = 0;

  mpz_t s;

  // for(){
  //     if(stoi(number)%10 ==0){
        
  //     }

  //   if(stoi(number)%2 ==1){
        
  //   }
  }

  return result;
}