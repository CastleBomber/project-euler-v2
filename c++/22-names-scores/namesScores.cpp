#include "namesScores.h"

int namesScores(vector<string> &names) {
    int total = 0;
    vector<int> namesValues;
    vector<int> namesScores;

    // Sort alphabetical order
    names = quickSort(names, 0, names.size() - 1);

    // Set alphabetial value for each name
    namesValues = setNamesValues(names);

    // Score = alphabetical value * alphabetical position
    namesScores = setNamesScores(namesValues);

    // Total = sum from all names scores
    total = sumNamesScores(namesScores);

    displayNamesScores(names, namesValues, namesScores);

    return total;
}

vector<string> readNamesFromFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    vector<string> names;
    string line;

    // Assuming the entire file content is stored in a single line
    if (getline(file, line)) {
        string name;

        for (char ch : line) {
            if (ch == '\"') {
                if (!name.empty()) {
                    names.push_back(name);
                    name.clear();
                }
            } else if (ch != ',') {
                name += ch;
            }
        }
    }

    file.close();
    return names;
}

/**
 * Quickly sorts into alphabetical order
 * Best time: O(nlog(n))
 *
 * Currently set to have Uppercase before lowercase
 * EX: AMY first, amy second
 *
 * @param names - unsorted vector of names
 * @param high - end of vector; iterates through recursion
 * @param low - beginning of vector; iterates through recursion
 * @return names - sorted in alphabetical order
 */
vector<string> quickSort(vector<string> &names, int low, int high) {
    if (low < high) {
        int pi = partition(names, low, high);

        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }

    return names;
}

/**
 * Used by quickSort to handle partitions of the initial vector
 * and swap poisitions of names so that
 * the left side has smaller elements, and the larger side has larger elements
 * in regard to the pivot
 *
 * @param names - unsorted vector becomes partially sorted
 * @param high - end of vector; iterates through recursion
 * @param low - beginning of vector; iterates through recursion
 * @return i - index of the pivot
 */
int partition(vector<string> &names, int low, int high) {
    string pivot = names[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (names[j] < pivot) {
            ++i;
            swap(names[i], names[j]);
        }
    }

    swap(names[i + 1], names[high]);

    return i + 1;
}

/**
 * Iterates through names and sums up the letters in a given name,
 * corresponding with their position in the alphabet,
 * to find their names' values
 *
 * @param names - strings parsed from text file
 * @return namesValues - vector of alphabetical values
 */
vector<int> setNamesValues(vector<string> &names) {
    vector<int> namesValues;
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                             'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (const auto &name : names) {
        int sum = 0;

        for (auto letter : name) {
            letter = toupper(letter);
            auto it = find(alphabet.begin(), alphabet.end(), letter);

            if (it != alphabet.end()) {
                sum += distance(alphabet.begin(), it) + 1;
            }
        }
        namesValues.push_back(sum);
    }

    return namesValues;
}

/**
 * Multiplies the alphabetical value of a name by its position in the list
 *
 * @param namesValues - vector of names' alphabetical values
 * @return namesScores - vector of names scores
 */
vector<int> setNamesScores(vector<int> &namesValues) {
    vector<int> namesScores;

    for (size_t i = 0; i < namesValues.size(); i++) {
        namesScores.push_back(namesValues[i] * (i + 1));
    }

    return namesScores;
}

/**
 *
 * @param namesScores - vector of names scores
 * @return sum - sum of all names scores
 */
int sumNamesScores(vector<int> &namesScores) {
    int sum = 0;

    for (auto score : namesScores) {
        sum += score;
    }

    return sum;
}

void displayNamesScores(vector<string> &names, vector<int> &namesValues,
                        vector<int> &namesScores) {
    for (int i = 0; i < names.size(); i++) {
        cout << i + 1 << ", Name: " << names[i] << ", Value: " << namesValues[i]
             << ", Score: " << namesScores[i] << endl;
    };
}