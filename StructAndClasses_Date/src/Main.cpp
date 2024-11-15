#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>

class Date {
public:
  static int DaysInMonth(int year, int month);
  static bool isLeapYear(int);

  int Day() const { return day; }
  void Day(int);
  int Month() const { return month; }
  void Month(int);
  int Year() const { return year; }
  void Year(int);
  std::string String() const;

  Date(int d, int m, int y);
  Date();

private:
  static constexpr int daysInMonth[]{31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};
  static constexpr const char *monthsByNames[]{
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};

  int day{1};
  int month{1};
  int year{0};
};

bool Date::isLeapYear(int y) {
  return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int Date::DaysInMonth(int y, int m) {
  // Error: Missing default case and bounds checking
  if (m < 1 || m > 12) {
    return INT_MAX; // Or throw an exception for invalid month
  }

  // Special handling for February
  if (m == 2 && isLeapYear(y)) {
    return 29;
  }

  return daysInMonth[m - 1];
}

// Use Initializer List to assign Date::year before the constructor runs
// Initializer List serve the purpose of
// 1. Initialize const members of the class
// 2. Initialize refs members of the class
// 3. Compiler optimizations
Date::Date(int d, int m, int y) : year(y) {
  Month(m);
  // As day of month depends on the month, assigning day goes the very last.
  Day(d);
}

Date::Date() : day(1), month(1), year(0) {}

// Crete definition of the method using Scope Resolution Date::
void Date::Day(int value) {
  if (value < 1)
    return;
  if (value > DaysInMonth(year, month))
    return;
  day = value;
}

// Crete definition of the method using Scope Resolution Date::
void Date::Month(int value) {
  if (value < 1)
    return;
  if (value > 12)
    return;
  month = value;
}

// Crete definition of the method using Scope Resolution Date::
void Date::Year(int value) {
  if (value < 0)
    return;
  year = value;
}

std::string Date::String() const {
  std::ostringstream oss;
  oss << monthsByNames[month - 1] << " " << day << ", " << year;
  return oss.str();
}

int main() {
  Date date{29, 8, 1981};
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);

  // Test default constructor
  Date defaultDate;
  assert(defaultDate.Day() == 1);
  assert(defaultDate.Month() == 1);
  assert(defaultDate.Year() == 0);

  // Test parameterized constructor with valid dates
  Date date1{29, 8, 1981};
  assert(date1.Day() == 29);
  assert(date1.Month() == 8);
  assert(date1.Year() == 1981);

  // Test setters with invalid values
  Date date2{15, 6, 2000};
  date2.Day(0);                 // Invalid day
  assert(date2.Day() == 15);    // Should remain unchanged
  date2.Month(13);              // Invalid month
  assert(date2.Month() == 6);   // Should remain unchanged
  date2.Year(-1);               // Invalid year
  assert(date2.Year() == 2000); // Should remain unchanged

  // Test setters with valid values
  date2.Day(20);
  date2.Month(7);
  date2.Year(2024);
  assert(date2.Day() == 20);
  assert(date2.Month() == 7);
  assert(date2.Year() == 2024);

  // Test isLeapYear static method
  assert(Date::isLeapYear(2000) == true);  // Divisible by 400
  assert(Date::isLeapYear(2100) == false); // Divisible by 100 but not 400
  assert(Date::isLeapYear(2024) == true);  // Divisible by 4 but not 100
  assert(Date::isLeapYear(2023) == false); // Not divisible by 4

  // Test NumberDaysInMonth static method
  // Test regular months
  assert(Date::DaysInMonth(2023, 1) == 31); // January
  assert(Date::DaysInMonth(2023, 4) == 30); // April

  // Test February in leap and non-leap years
  assert(Date::DaysInMonth(2023, 2) == 28); // Non-leap year
  assert(Date::DaysInMonth(2024, 2) == 29); // Leap year

  // Test invalid months
  assert(Date::DaysInMonth(2023, 0) == INT_MAX);  // Below range
  assert(Date::DaysInMonth(2023, 13) == INT_MAX); // Above range

  // Test edge cases
  Date edgeDate1{31, 1, 2023}; // Valid 31-day month
  assert(edgeDate1.Day() == 31);

  Date edgeDate2{31, 4, 2023};  // Invalid day for 30-day month
  assert(edgeDate2.Day() == 1); // Should use default value

  // Test February edge cases
  Date febDate1{29, 2, 2024}; // Valid leap year
  assert(febDate1.Day() == 29);

  Date febDate2{29, 2, 2023};  // Invalid - not a leap year
  assert(febDate2.Day() == 1); // Should use default value

  Date dateToString(29, 8, 1981);
  assert(dateToString.String() == "August 29, 1981");

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
