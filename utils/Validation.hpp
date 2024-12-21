#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>

using namespace std;

// Function to validate if the given date is valid
bool validateDate(int year, int month, int day) {
    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a value between 1 and 12.\n";
        return false;
    }

    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
            break;
        default:
            return false;
    }

    if (day < 1 || day > daysInMonth) {
        cout << "Invalid day for the given month. The month " << month << " has only " << daysInMonth << " days.\n";
        return false;
    }

    return true;
}

// Function to validate if the time falls within clinic hours (08:00 to 17:00)
bool validateTime(int hour, int minute) {
    if (hour < 8 || hour > 17 || (hour == 17 && minute > 0)) {
        cout << "Invalid time. Clinic hours are from 08:00 to 17:00.\n";
        return false;
    }

    if (minute < 0 || minute > 59) {
        cout << "Invalid minute. Please enter a value between 0 and 59.\n";
        return false;
    }

    return true;
}

#endif // VALIDATION_HPP
