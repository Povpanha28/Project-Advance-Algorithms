#ifndef TMS_HPP
#define TMS_HPP

#include <iostream>
#include <vector>
using namespace std;

class TimeSlot {
private:
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;

public:
    // Constructor for TimeSlot
    TimeSlot(int sh, int eh, int sm = 0, int em = 0)
        : startHour(sh), startMinute(sm), endHour(eh), endMinute(em) {}

    // Getters for private members
    int getStartHour() const { return startHour; }
    int getStartMinute() const { return startMinute; }
    int getEndHour() const { return endHour; }
    int getEndMinute() const { return endMinute; }

    // Setters for private members
    void setStartHour(int sh) { startHour = sh; }
    void setStartMinute(int sm) { startMinute = sm; }
    void setEndHour(int eh) { endHour = eh; }
    void setEndMinute(int em) { endMinute = em; }

    // Display the time slot in a readable format
    void displayTimeSlot() const {
        cout << "Start: " << startHour << ":" << (startMinute < 10 ? "0" : "") << startMinute
             << ", End: " << endHour << ":" << (endMinute < 10 ? "0" : "") << endMinute << endl;
    }
};

class Clinic {
private:
    TimeSlot clinicHours;  // Represents the clinic's operating hours

public:
    // Constructor initializes default clinic hours (8 AM to 5 PM)
    Clinic() : clinicHours(8, 17) {}

    // Method to set clinic hours
    void setClinicHours(int startHour, int endHour) {
        if (startHour < 0 || startHour > 23 || endHour < 0 || endHour > 23 || startHour >= endHour) {
            throw invalid_argument("Invalid clinic hours. Ensure startHour < endHour and within 0-23.");
        }
        clinicHours.setStartHour(startHour);
        clinicHours.setEndHour(endHour);
        cout << "Clinic hours set successfully: " << startHour << ":00 to " << endHour << ":00\n";
    }

    // Method to view clinic hours
    void viewClinicHours() const {
        cout << "Clinic is open from " << clinicHours.getStartHour() << ":00 to " << clinicHours.getEndHour() << ":00 every day.\n";
    }
};

#endif // TMS_HPP
