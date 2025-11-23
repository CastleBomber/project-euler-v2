#!/usr/bin/env python3
'''
********************************************************
# Project Euler Problem 26
# Solution by Sajjadeportivo
#
# *Python code is optimized for primes 'not divisible by 2 or 5'
*********************************************************
'''
max = 0
y = 3
for x in range(7,1000,2):
    if x%5 != 0:
        cycle = ''
        a = 10%x
        b = 10//x
        cycle = str(b)

        # For unit fractions with primes like 7, 13, 17…, 
        # the repeating cycle always starts when the remainder hits 1
        while a!=1:
            a*=10
            b=a//x
            cycle += str(b)
            a=a%x
    if len(cycle) > max:
        max = len(cycle)
        y = x
print(y)