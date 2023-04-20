﻿/**
 * Author: CBOMBS
 * Date: December 26th, 2022
 * Project Euler: #14 Longest Collatz Sequence
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
 * Shortcuts:
 *  VS Code:
 * 	    c++ VS Code clang-formatter: shift+alt+f
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
#include <map>
#include <future>


    using namespace std;

int collatzSequence(map<int, int>& table, int startingNumber);
int checkTabulization(map<int, int>& table, int number);
int isOdd(int number);

/**
 *  Increases odd numbers and decreases even numbers
 *  with the goal of finishing at 1
 *
 * Mimimum acceptable value is 1. All lower numbers will be returned as an error.
 * For this reason, we set: sequenceCount = 1
 *
 *  returns
 *      sequenceCount - number of terms to reach 1, includes starting number
 */
int collatzSequence(map<int, int>& table, int startingNumber)
{
    int currentNumber = startingNumber; // decrements through sequence until reaches 1
    int sequenceCount = 1;              // number of terms for given number to reach 1
    int tableResult = 0;                // return value from check Tabulization

    // Error Check
    if (startingNumber < 1)
    {
        printf("Error: value should not be less than 1\n");

        return 0;
    }

    // Loops and updates given number until its value is 1
    while ((currentNumber != 1))
    {
        tableResult = checkTabulization(table, currentNumber);

        // Check if number already in the table
        if (tableResult)
        {
            sequenceCount += tableResult;
            return sequenceCount;
        }

        if (isOdd(currentNumber))
        {
            // Odd number -> increased and becomes even
            currentNumber = (3 * currentNumber) + 1;
        }
        else
        {
            // Even number -> decreases and becomes odd || even
            currentNumber = currentNumber / 2;
        }

        sequenceCount++;
    }

    /*for (const auto& x : y) {
        std::async(std::launch::async(), x);
    }*/

    table.emplace(startingNumber, sequenceCount); // Add to table

    return sequenceCount;
}

/**
 * Checks if number is in the table
 *
 * If the given number is not in the table, return 0
 *
 * tabulization - top-down dynamic approach,
 * uses extra memory to store solutions to sub problems
 * avoids recomputation
 *
 * Ex: if the number is in the table:
 * input number = 5, return = 6  (includes itself)
 * 5 → 16 → 8 → 4 → 2 → 1
 *
 * table.emplace() - make them a pair and add to map
 *
 */
int checkTabulization(map<int, int>& table, int number)
{
    int sequenceLength = 0;

    if (auto search = table.find(number); search != table.end())
    {
        sequenceLength = search->second;
    }

    return sequenceLength;
}

int isOdd(int number)
{
    int status = 0;

    if ((number % 2) > 0)
    {
        status = 1;
    }

    return status;
}

int main()
{
    map<int, int> table;          // stores each number and its chain count
    int longestChainProducer = 0; // produces the longest chain in the sequence
    int longestChainCount = 0;    // stores the highest value of currentChainCount from longestChainProducer
    int currentTerm = 989999;          // checks for which number gives the largest sequence
    int maxTerm = 1000000;             // largest number to check
    int currentChainCount = 0;    // current number's chain count

    while (currentTerm != maxTerm)
    {
        currentChainCount = collatzSequence(table, currentTerm);

        if (longestChainCount < currentChainCount)
        {
            longestChainCount = currentChainCount;
            longestChainProducer = currentTerm;
        }

        currentTerm++;
    }

    cout << "The number: " << longestChainProducer
        << " produces the longest chain with: " << longestChainCount << " terms\n";
}
