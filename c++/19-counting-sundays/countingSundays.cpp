#include "countingSundays.h" // 4

/**
 * Counts the number of 1st Sundays within each year
 * and returns the largest count from the years
 *
 * @param start - {M,D,Y} => {1, 1, 1901}
 * @param end - {M,D,Y} => {12, 31, 2000}
 * @return maxSundays
 */
int countingSundays(vector<int> start, vector<int> end) {
  vector<Items> yearsList;
  int maxSundays = 0;

  // Initialize list: year, LY value, and count of 0
  yearsList = initialiazeList(start[2], end[2]);

  // Builds up list with the number of 1st Sundays in each year
  yearsList = buildList(start, end);

  // Iterate through yearsList to find the greatest count
  maxSundays = getMaxFromList(yearsList);

  return maxSundays;
}

/**
 * 1901 is the start of the 20th century and this list
 * Adds all the years in between this and the given endYear
 * Marks if they are leap years or not
 *
 * @param start - {M,D,Y} => {1, 1, 1901}
 * @param end - {M,D,Y} => {12, 31, 2000}
 * @return yearsList - <year, leapYear, firstSundays>
 */
vector<Items> initialiazeList(vector<int> start, vector<int> end) {
  vector<Items> yearsList;
  int startYear = start[0]; // Start of 20th century: 1901
  int endYear = end[0];     // End of 20th century: 2000

  for (int curYear = startYear; curYear < endYear; curYear++) {
    if (checkLeapYear(curYear)) {
      yearsList.emplace_back(curYear, 1, 0);
    } else {
      yearsList.emplace_back(curYear, 0, 0);
    }
  }

  return yearsList;
}

/**
 * Builds up list with the number of 1st Sundays in each year
 *
 * @param start - {M,D,Y} => {1, 1, 1901}
 * @param end - {M,D,Y} => {12, 31, 2000}
 * @return yearsList
 */
vector<Items> buildList(vector<int> start, vector<int> end) {
  vector<Items> yearsList;
  vector<int> daysMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int startYear = start[2];
  int endYear = end[2];

  // Add number of first Sundays to each item in the year list
  for (int curYear = startYear; curYear < endYear; curYear++) {
    yearsList[curYear - startYear].count = getYearsFirstSundaysCount(curYear);
  }
}

/**
 * Counts the number of first Sundays that are in each year
 *
 * @param year - year within the 20th century
 * @return count - number of first Sundays in given year
 */
int getYearsFirstSundaysCount(int year) {
  vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<int> monthsLY = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int count = 0;
  int start = 0; // Days b/n Sun-Sat

  start = getFirstDayOfYear(year); // Sun-Sat

  if (1) {
    count += 1;
  }

  return count;
}

/**
 *
 * year - 1901
 * 1901 => 2 (Tuesday)
 * 1902 - 1901 = 1
 * 1902 => Tuesday + 1 = Wednesday
 *
 * @param year - year within the 20th century
 * @return day - day of the week (Sun-Sat)
 */
int getFirstDayOfYear(int year) {
  vector<int> week = {0, 1, 2, 3, 4, 5, 6}; // Sun,M,T,W,Th,F,Sa
  int startYear20thCentury = 1901;
  int startDay20thCentury = 2; // Tuesday
  int addDay = 0;

  addDay = year - startYear20thCentury; // Ex: 1906-1901 = 5
  //addDay + (addDay/3)

  for () {
    if () {
      //366%7=1
    } else {
      //365%7=2
    }
  }

  return day;
}

/**
 * Returns the leap year status of the given year
 *
 * @param year - year within the 20th century
 * @return leapYear - true if leap year, false if not
 */
int checkLeapYear(int year) {
  int leapYear = 0;

  if (((year % 4 == 0) && (year % 100 != 0)) ||
      ((year % 100 == 0) && (year % 400 == 0))) {
    leapYear = 1;
  }

  return leapYear;
}

int getMaxFromList(vector<Items> list) { return 4; }