#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> readNamesFromFile(const string &filename);
int namesScores(vector<string> &names);
vector<string> quickSort(vector<string> &names, int low, int high);
int partition(vector<string> &names, int low, int high);
vector<int> setNamesValues(vector<string> &names);
vector<int> setNamesScores(vector<int> &namesValues);
int sumNamesScores(vector<int> &namesScores);
void displayNamesScores(vector<string> &names, vector<int> &namesValues,
                        vector<int> &namesScores);

#endif