#!/usr/bin/env python
'''
********************************************************
    Author: CBombs
    Date:   April 18th, 2024

    Project Euler: #20 Factorial Digit Sum

    n! = n * (n-1) * (n-2) * ... * 1
    For example, 10! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 = 3,628,800
    and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
    Find the sum of the digits in the number 100!.

    Solution:
        100! = 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
        SumOfDigits(100!) = 648

    Notes:
        Numpy - handle many very large whole numbers

    Replit:
        Menu - cmd+j
        Code folding - Toggle all folds from menu option

    Debugger:
        Breakpoints and for loops require two taps to proceed
        
*********************************************************
'''

from functions import *
import math


def main():
    # Simplest solution using the math library to get 100!
    factorial_100 = math.factorial(100)

    print("SumOfDigits is: ")
    print(SumOfDigits(factorial_100))

    # Showcasing how I would solve with NumPy
    # May be more optimal for storing numbers when going through calculations
    numpy_num = np.array([factorial_100])

    print("SumOfDigitsNumpy is: ")
    print(SumOfDigitsNumpy(numpy_num))


main()
