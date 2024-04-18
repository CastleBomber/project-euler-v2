#ifndef MAIN_H_
#define MAIN_H_

#include <bitset>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <thread>
#include <regex>

using namespace std;

vector<vector<int>> getMatrixFromFile(vector<vector<int>> &Matrix, string file_name);
int maxPath(vector<vector<int>> &Matrix);
int solveTriangleSum(int head, int bottomLeft, int bottomRight);
void testMatrix(vector<vector<int>> &Matrix);

#endif