#ifndef MAIN_H_
#define MAIN_H_

#include <bitset>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Items {
  int year, leapYear, count;
};

int countingSundays(vector<int> start, vector<int> end);
vector<Items> initialiazeList(vector<int> start, vector<int> end);
vector<Items> buildList(vector<int> start, vector<int> end);
int getYearsFirstSundaysCount(int year);
int getFirstDayOfYear(int year);
int checkLeapYear(int year);
int getMaxFromList(vector<Items> list);

#endif