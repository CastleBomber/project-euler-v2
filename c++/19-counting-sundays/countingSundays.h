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

  Years(int y, int ly, int sd, int fsc) { // Constructor with parameters
    year = y;
    leapYear = ly;
    startDay = sd;
    firstSundaysCount = fsc;
  }
};

int countingSundays(vector<int> start, vector<int> end);
vector<Years> initialiazeList(vector<int> start, vector<int> end);
vector<Years> buildList(vector<int> start, vector<int> end);
int getYearsFirstSundaysCount(int year);
int getFirstDayFromYearIn20thCentury(int year);
int checkLeapYear(int year);
int getMaxFromList(vector<Years> list);

#endif