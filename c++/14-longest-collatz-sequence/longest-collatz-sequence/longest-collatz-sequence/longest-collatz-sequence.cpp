﻿/**
 * Author: CBOMBS
 * Date: December 26th, 2022
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * Examples:
 * 1 - returns 1 becuase its the number of terms in the sequence
 * 2 - returns 2
 * 3 - returns 8
 * 4 - returns 3
 *
 * References:
 * https://www.enjoyalgorithms.com/blog/top-down-memoization-vs-bottom-up-tabulation
 *
 * Acknowledgments:
 * Haskell's Solution from Project Euler
 *
 * Shortcuts:
 *  VS Code:
 * 	    c++ VS Code clang-formatter: shift+alt+f
 *
 * Notes:
 *                 bytes    range of values
 * int	            4	    -2,147,483,648 to 2,147,483,647
 * unsigned long	4	    0 to 4,294,967,295
 *
 * why does 'unsigned long work' but not int?
 * Perhaps needed a much higher value than predicted (1 million * 10, roughly).
 *
 *  Visual Studio:
 *      code folding: select region, ctrl+m+m
 *      full-screen: shift+alt+enter
 *		solution explorer: shift+alt+L
 *      (start debugger to access watchlist)
 *      watchlist: ctrl+alt+W,1
 *      add to watchlist: shift+F9
 *
 */

#include <iostream>
#include <stdio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    int longestTermsNumber = 0;  // produces the longest chain in the sequence
    int longestTermsCount = 0;   // stores the highest value of curTermsCount from longestChainProducer
    int curTermsCount = 0;       // current number's chain count
    unsigned long curNumber = 1; // manipulated by Collatz Sequence, inc range of values
    int maxNumber = 1000000;     // largest number to check
    int i = 1;                   // outer loop number utilized by curNumber

    for (i = 1; i < maxNumber; i++)
    {
        curNumber = i;
        curTermsCount = 1;

        while (curNumber != 1)
        {
            curTermsCount++;

            if (curTermsCount > longestTermsCount)
            {
                longestTermsCount = curTermsCount;
                longestTermsNumber = i;
            }

            if (curNumber % 2 == 0)
            {
                curNumber = curNumber / 2;
            }
            else
            {
                curNumber = curNumber * 3 + 1;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "The number: " << longestTermsNumber
         << " produces the longest chain with: " << longestTermsCount << " terms\n"
         << "Time: " << duration.count() << " microseconds" << endl;
}
