#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to validate if the given date is valid (checks month, day, and leap year)
// Function to validate if the given date is valid (checks month, day, and leap year)
bool validateDate(int year, int month, int day) {
    // Check if the month is valid
    if (month < 1 || month > 12) {
        cout << "Invalid month. Month should be between 1 and 12." << endl;
        return false;
    }

    // Determine the number of days in the given month
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; // January, March, May, July, August, October, December
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; // April, June, September, November
            break;
        case 2:
            // Check for leap year (February)
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29; // Leap year
            } else {
                daysInMonth = 28; // Not a leap year
            }
            break;
        default:
            cout << "Invalid month. Please check the month value." << endl;
            return false;
    }

    // Check if the day is valid for the given month
    if (day < 1 || day > daysInMonth) {
        cout << "Invalid day for the given month. The month " << month << " has only " << daysInMonth << " days." << endl;
        return false;
    }

    return true; // Date is valid
}


// Function to validate if the given time is valid within clinic hours (08:00 to 17:00)
bool validateTime(int hour, int minute) {
    // Check if the time falls within clinic hours
    if (hour < 8 || hour > 17 || (hour == 17 && minute > 0)) {
        cout << "Invalid time. Clinic hours are from 08:00 to 17:00." << endl;
        return false;
    }

    // Check if minute is valid
    if (minute < 0 || minute > 59) {
        cout << "Invalid minute. Minute should be between 0 and 59." << endl;
        return false;
    }

    return true; // Time is valid
}

#endif
