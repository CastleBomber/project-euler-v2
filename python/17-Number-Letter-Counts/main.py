#!/usr/bin/env python

'''
  Author: CBombs
  Date: September 18th, 2023

  Project Euler: #17 Number Letter Counts

  If the numbers 1 to 5 are written out in words: one, two three, four, five,
  then there are: 3 + 3 + 5 + 4 + 4 = 19 letter used in total.

  If all the numbers from 1 to 1000 inclusive were written out in words,
  how many letters would be used? Do not count spaces or hyphens

  Individual Number Count Ex:
  342 (three hundred and forty-two) - contains 23 letters
  115 (one hundred and fifteen) - contains 20 letters

  Solution:
    Python - 21124 Letters

'''

from numberLetterCounts import *

def main():
  highestNum = 1000
  sum = 0

  sum = solution(highestNum)

  print(sum)

main()