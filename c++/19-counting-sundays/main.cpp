/**
 * Author: CBombs
 * Date: October 16th, 2023
 *
 * Project Euler: #19 Counting Sundays
 *
 * You are given the following information,
 * but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4,
 * but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the 1st of the month during the 20th century
 * (Tuesday, 1 Jan 1901 to Sunday, 31 Dec 2000)?
 *
 * Solution:
 *  (ongoing)
 *
 * Notes:
 * Monday, January 1st, 1900 // Not LY
 *
 * Tuesday, January 1st, 1901
 * Friday, February 1st, 1901
 * Friday, March 1st, 1901
 * Monday, April 1st, 1901
 * Wednesday, May 1st, 1901
 * Saturday, June 1st, 1901
 * Monday, July 1st, 1901
 * Thursday, August 1st, 1901
 * Sunday, September 1st, 1901 // $
 * Tuesday, October 1st, 1901
 * Friday, November 1st, 1901
 * Sunday, December 1st, 1901 // $
 *
 * Wednesday, January 1st, 1902
 * Thursday, January 1st, 1903
 *
 * Friday, January 1st, 1904 // LY
 * Monday, February 1st, 1904
 * Tuesday, March 1st, 1904
 * Friday, April 1st, 1904
 * Sunday, May 1st, 1904 // $
 * Wednesday, June 1st, 1904
 * Friday, July 1st, 1904
 * Monday, August 1st, 1904
 * Thursday, September 1st, 1904
 * Saturday, October 1st, 1904
 * Tuesday, November 1st, 1904
 * Thursday, December 1st, 1904
 *
 * Sunday, January 1st, 1905 // $
 * Monday, January 1st, 1906
 * Tuesday, January 1st, 1907
 * Wednesday, January 1st, 1908 // LY
 * Friday, January 1st, 1909
 * Saturday, January 1st, 1910
 * Sunday, January 1st, 1911 // $
 * Monday, January 1st, 1912 // LY
 * Wednesday, January 1st, 1913
 *
 * Sites:
 * https://www.timeanddate.com/calendar/?year=1902&country=1
 *
 * Replit:
 *   Menu - cmd+j
 *   Code folding - Toggle all folds from menu option
 *
 */

#include "countingSundays.h"

int main() {
  vector<int> startDate = {1, 1, 1901};
  vector<int> endDate = {12, 31, 2000};
  int answer = 0;

  answer = countingSundays(startDate, endDate);

  cout << "The answer is: " << answer << endl;

  return 0;
}