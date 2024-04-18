#include "countingSundays.h"

/**
 * Counts the number of 1st Sundays within each year
 * and returns the largest count from the years
 *
 * @param start - {M,D,Y} => {1, 1, 1901}
 * @param end - {M,D,Y} => {12, 31, 2000}
 * @return maxSundays
 */
int countingSundays(vector<int> start, vector<int> end) {
  vector<Years> yearsList;
  int maxSundays = 0;

  // Initialize list: year, LY value, and count of 0
  yearsList = initializeYears(start, end);

  // Set the leap years for each year
  yearsList = setLeapYears(yearsList);

  // Set the day of the week that each year starts on
  yearsList = setStartDays(yearsList);

  // Builds up list with the number of 1st Sundays in each year
  yearsList = setFirstSundaysCounts(yearsList);

  // Iterate through yearsList to find the greatest count
  maxSundays = getFirstSundaysTotal(yearsList);

  // test(yearsList);

  return maxSundays;
}

/**
 * 1901 is the start of the 20th century and this list
 * Adds all the years in between this and the given endYear
 * Marks if they are leap years or not
 *
 * @param start - {M,D,Y} => {1, 1, 1901}
 * @param end - {M,D,Y} => {12, 31, 2000}
 * @return yearsList - <year, leapYear, startDay, firstSundaysCount>
 */
vector<Years> initializeYears(vector<int> start, vector<int> end) {
  vector<Years> yearsList;
  int startYear = start[2]; // Start of 20th century: 1901
  int endYear = end[2];     // End of 20th century: 2000

  for (int curYear = startYear; curYear <= endYear; curYear++) {
    yearsList.emplace_back(curYear, 0, 0, 0);
  }

  return yearsList;
}

/**
 * Sets the leap year values
 *
 * @param _yearsList
 * @return yearsList
 */
vector<Years> setLeapYears(vector<Years> _yearsList) {
  vector<Years> yearsList = _yearsList;
  int curYear = 0;

  for (int i = 0; i < _yearsList.size(); i++) {
    curYear = yearsList[i].year;

    if (checkLeapYear(curYear)) {
      yearsList[i].leapYear = 1;
    } else {
      yearsList[i].leapYear = 0;
    }
  }

  return yearsList;
}

/**
 * Returns the day the year starts on
 * Representing Sun-Sat as: 0-6
 * Function is specific to 20th century
 *
 * Formula:
 * DIFF = year - 1901
 * ^LY = DIFF/4
 * year => 1901s_TUESDAY + DIFF = (2 + 0) = DAY%7 (Week[DAY] is the start of the
 * year)
 *
 * Ex:
 * 1901 - 1901 = 0
 * ^LY = 0/4 = 0
 * 1901 => 1901s_TUESDAY + DIFF + ^LY = (2 + 0 + 0) = 2%7 = 2 (Tuesday is the
 * start of the 1901)
 *
 * 1902 - 1901 = 1
 * ^LY = 1/4 = 0
 * 1902 => 1901s_TUESDAY + DIFF ^LY = (2 + 1 + 0) = 3%7 = 3 (Wednesday is the
 * start of 1902)
 *
 * 1903 - 1901 = 2
 * ^LY = 2/4 = 0
 * 1903 => 1901s_TUESDAY + DIFF + ^LY = (2 + 2 + 0) = 4%7 = 4 (Thursday is the
 * start of 1903)
 *
 * 1904 - 1901 = 3 (Leap year! Affects the following year)
 * ^LY = 3/4 = 0
 * 1904 => 1901s_TUESDAY + DIFF + ^LY = (2 + 3 + 0) = 5%7 = 5 (Friday is the
 * start of 1904)
 *
 * 1905 - 1901 = 4 + LY (Add a 1 day shift due to past leap year)
 * ^LY = 4/4 = 1
 * 1905 => 1901s_TUESDAY + DIFF + ^LY = (2 + 4 + 1) = 7%7 = 0 (Sunday is the
 * start of 1905)
 *
 * 1906 - 1901 = 5
 * ^LY = 5/4 = 1
 * 1906 => 1901s_TUESDAY + DIFF + ^LY = (2 + 5 + 1) = 8%7 = 1 (Monday is the
 * start of 1906)
 *
 * 1909 - 1901 = 8
 * ^LY = 8/4 = 2
 * 1909 => 1901s_TUESDAY + DIFF + ^LY = (2 + 8 + 2) = 12%7 = 5 (Friday is the
 * start of 1909)
 *
 * 1999 - 1901 = 98
 * ^LY = 98/4 = 24
 * 1999 => 1901s_TUESDAY + DIFF + ^LY =  (2 + 98 + 24) = 124%7 = 5 (Friday is
 * the start of 1999)
 *
 * 2000 - 1901 = 99
 * ^LY = 99/4 = 24
 * 2000 => 1901s_TUESDAY + DIFF + ^LY =  (2 + 99 + 24) = 125%7 = 6 (Saturday is
 * the start of 2000)
 *
 * @param _yearsList
 * @return yearsList
 */
vector<Years> setStartDays(vector<Years> _yearsList) {
  vector<Years> yearsList = _yearsList;
  vector<int> week = {0, 1, 2, 3, 4, 5, 6}; // Sun,M,T,W,Th,F,Sa (0-6)
  int startYear20thCentury = 1901;          // First year in 20th century
  int startDay20thCentury = 2; // Tuesday, first day in 20th century
  int diff = 0;
  int leaps = 0;
  int _startDay = 0;

  // Algorithm to add start days to years
  for (int x = 0; x < _yearsList.size(); x++) {
    diff = yearsList[x].year - startYear20thCentury;
    leaps = diff / 4;
    _startDay = (startDay20thCentury + diff + leaps) % 7;
    yearsList[x].startDay = (startDay20thCentury + diff + leaps) % 7;
  }

  return yearsList;
}

/**
 * Builds up list with the number of 1st Sundays for each year
 *
 * @param _yearsList
 * @return yearsList - <year, leapYear, startDay, firstSundaysCount>
 */
vector<Years> setFirstSundaysCounts(vector<Years> _yearsList) {
  vector<Years> yearsList;
  int startYear = 0;
  int endYear = 0;
  int pos = 0;
  int curYear = 0;
  yearsList = _yearsList;

  // Scope of the 20th century years
  startYear = yearsList[0].year;
  endYear = yearsList[yearsList.size() - 1].year;

  // Add total number of 1st Sundays to each year
  for (curYear = startYear; curYear <= endYear; curYear++) {
    pos = curYear - startYear;

    yearsList[pos].firstSundaysCount = getFirstSundaysCountForYear(
        yearsList[pos].startDay, yearsList[pos].leapYear);
  }

  return yearsList;
}

/**
 * Builds up list with the number of 1st Sundays for specific year
 *
 * @param _startDay - Sun,M,T,W,Th,F,Sa (0-6)
 * @param _daysInMonths - correct days for YR/LY
 * @return count - number of 1st Sundays in the year
 */
int getFirstSundaysCountForYear(int _startDayOfYear, int _leapYear) {
  int count = 0;
  int leapYear = 0;
  bool isSunday = 0;
  int startDayOfMonth = 0;
  vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<int> daysInMonthsLY = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  startDayOfMonth = _startDayOfYear;
  leapYear = _leapYear;

  // If leap year, switch the days
  if (leapYear) {
    daysInMonths = daysInMonthsLY;
  }

  // Add up the 1st Sundays through the year
  for (int month = 0; month < daysInMonths.size(); month++) {
    startDayOfMonth = getStartOfMonth(startDayOfMonth, daysInMonths[month]);

    if (startDayOfMonth == 0) {
      count += 1;
    }
  }

  return count;
}

/**
 *
 * @param _startDay - Sun,M,T,W,Th,F,Sa (0-6)
 * @return isSunday - true: Sunday, false: not Sunday
 */
int getStartOfMonth(int _startDay, int _daysInThisMonth) {
  int startDayOfMonth = 0;
  int daysInThisMonth = 0;

  startDayOfMonth = _startDay;
  daysInThisMonth = _daysInThisMonth;

  startDayOfMonth = (startDayOfMonth + daysInThisMonth) % 7;

  return startDayOfMonth;
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

int getFirstSundaysTotal(vector<Years> _yearsList) {
  int total = 0;

  vector<Years> yearsList;
  yearsList = _yearsList;

  for (int i = 0; i < yearsList.size(); i++) {
    total += yearsList[i].firstSundaysCount;
  }

  return total;
}

// Testing specific years at end
void test(vector<Years> _yearsList) {
  vector<Years> yearsList;

  yearsList = _yearsList;

  // Test end of years list
  vector<Years> tmp1, tmp2, tmp3;
  tmp1.emplace_back(yearsList[yearsList.size() - 1]);
  tmp2.emplace_back(yearsList[yearsList.size() - 2]);
  tmp3.emplace_back(yearsList[yearsList.size() - 3]);

  // Test front of years list
  // tmp1.emplace_back(yearsList[0]);
  // tmp2.emplace_back(yearsList[1]);
  // tmp3.emplace_back(yearsList[2]);
}
