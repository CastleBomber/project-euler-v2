#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>
#include <stdio.h>

#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Years {
    int year, leapYear, startDay, firstSundaysCount;

    // Constructor with parameters
    Years(int _year, int _leapYear, int _startDay, int _firstSundaysCount) {
        year = _year;
        leapYear = _leapYear;
        startDay = _startDay;
        firstSundaysCount = _firstSundaysCount;
    }
};

int countingSundays(vector<int> start, vector<int> end);
vector<Years> initializeYears(vector<int> start, vector<int> end);
vector<Years> setLeapYears(vector<Years> _yearsList);
vector<Years> setStartDays(vector<Years> _yearsList);
vector<Years> setFirstSundaysCounts(vector<Years> _yearsList);
int getFirstSundaysCountForYear(int _startDay, int _leapYear);
int checkLeapYear(int year);
int getMaxFromList(vector<Years> list);
void test(vector<Years> _yearsList);

#endif