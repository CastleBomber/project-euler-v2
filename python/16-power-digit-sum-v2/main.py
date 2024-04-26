#!/usr/bin/env python
'''
********************************************************
    Author: CBombs
    Date:   April 18th, 2024

    Project Euler: #16 Power Digit Sum

    2^15 = 32,768 and the sum of its digits is 3+2+7+6+8 = 26.
    What is the sum of the digits of the number 2^1000?

    Solution:
        Sum of digits in 2^1000 = 1366

    Notes:
        Numpy - handle many very large whole numbers

    Replit:
        Menu - cmd+j
        Code folding - Toggle all folds from menu option

    Debugger:
        Breakpoints and for loops require two taps to proceed
        
*********************************************************
'''

import math


def main():
    total_sum = 0
    result = 0
    result_str = ""

    result = 2**1000
    result_str = str(result)

    for digit in result_str:
        total_sum += int(digit)

    print("Sum: ")
    print(total_sum)


main()
