#include "maximumPathSum.h"

/**
 * Computes the highest valued path sum
 * when traversing down through a triangle matrix
 *
 * @param &Matrix - triangle of numbers
 * @return result - sum of path
 */
int maxPath(vector<vector<int>> &Matrix) {
  int result = 0;

  // Bottoms up approach
  // Rows, start from second to last
  for (int i = Matrix.size() - 2; i >= 0; i--) {
    for (int j = 0; j < Matrix[i].size(); j++) {
      // Head of triangle compared with bottom left, right nodes
        Matrix[i][j] = solveTriangleSum(Matrix[i][j], Matrix[i+1][j], Matrix[i+1][j+1]);
    }
  }

  result = Matrix[0][0];

  return result;
}

/**
 * Sums up the two largest numbers in triagle
 *
 * @param Node
 * @return result - sum
 */
int solveTriangleSum(int head, int bottomLeft, int bottomRight) {
  int result = 0;

  if(bottomLeft > bottomRight){
    result = head + bottomLeft;
  } else{
    result = head + bottomRight;
  }
  
  return result;
}

void testMatrix(vector<vector<int>> &Matrix) {
  cout << "Matrix.size() " << Matrix.size() << endl;      // 4
  cout << "Matrix[0].size()" << Matrix[0].size() << endl; // 1
  cout << "Matrix[1].size()" << Matrix[1].size() << endl; // 2
  cout << "Matrix[2].size()" << Matrix[2].size() << endl; // 3
  cout << "Matrix[3].size()" << Matrix[3].size() << endl; // 4
}

/**
 * Open file and build a matrix
 *
 * @param &Matrix
 * @param file_name
 * @return Matrix
 */
vector<vector<int>> getMatrixFromFile(vector<vector<int>> &Matrix,
                                      string file_name) {
  string line;
  ifstream infile(file_name);

  while (!infile.eof()) {
    regex re(" ");
    vector<int> row;

    getline(infile, line);
    sregex_token_iterator first{line.begin(), line.end(), re, -1}, last;
    vector<string> tokens{first, last};

    for (auto token : tokens) {
      row.push_back(stoi(token));
    }

    Matrix.push_back(row);
  }

  infile.close();

  return Matrix;
}
