#ifndef APPOINTMENTMANAGEMENT_HPP
#define APPOINTMENTMANAGEMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Patient_Manage.hpp" // Include the PatientManagement class for access to patient data
#include "Validation.hpp"

using namespace std;

// Appointment class to hold appointment data
class Appointment
{
public:
    int patientId;          // Patient's ID
    char appointmentDate[11]; // Appointment Date (e.g., "2024-12-21")
    char appointmentTime[6];  // Appointment Time (e.g., "10:00")
    char description[256];    // Reason for the appointment (optional)

    Appointment(int patientId = 0, string appointmentDate = "", string appointmentTime = "", string description = "")
        : patientId(patientId)
    {
        strncpy(this->appointmentDate, appointmentDate.c_str(), sizeof(this->appointmentDate) - 1);
        this->appointmentDate[sizeof(this->appointmentDate) - 1] = '\0';

        strncpy(this->appointmentTime, appointmentTime.c_str(), sizeof(this->appointmentTime) - 1);
        this->appointmentTime[sizeof(this->appointmentTime) - 1] = '\0';

        strncpy(this->description, description.c_str(), sizeof(this->description) - 1);
        this->description[sizeof(this->description) - 1] = '\0';
    }
};

class AppointmentManagement
{
private:
    PatientManagement &patientManager; // Reference to PatientManagement class

public:
    vector<Appointment> appointments; // Vector to store all appointments

    // Constructor accepts a reference to PatientManagement
    AppointmentManagement(PatientManagement &patientManager) : patientManager(patientManager) {}

    // Function to book an appointment
    void bookAppointment()
    {
        int patientId, year, month, day, hour, minute;
        string description;

        cout << "Enter Patient ID: ";
        cin >> patientId;

        // Check if the patient exists in the system
        if (patientManager.searchPatient(patientId) == nullptr)
        {
            cout << "Patient ID not found. Appointment not booked.\n";
            return;
        }

        cout << "Enter appointment date (YYYY MM DD): ";
        cin >> year >> month >> day;
        cout << "Enter appointment time (HH MM): ";
        cin >> hour >> minute;
        cin.ignore(); // Clear the input buffer
        cout << "Enter description (optional): ";
        getline(cin, description);

        // Validate the date
        if (!validateDate(year, month, day))
        {
            cout << "Invalid date. Appointment not booked.\n";
            return;
        }

        // Validate the time
        if (!validateTime(hour, minute))
        {
            cout << "Invalid time. Appointment not booked.\n";
            return;
        }

        // Format date and time
        string formattedDate = to_string(year) + "-" +
                               (month < 10 ? "0" : "") + to_string(month) + "-" +
                               (day < 10 ? "0" : "") + to_string(day);
        string formattedTime = (hour < 10 ? "0" : "") + to_string(hour) + ":" +
                               (minute < 10 ? "0" : "") + to_string(minute);

        // Book the appointment
        appointments.emplace_back(patientId, formattedDate, formattedTime, description);
        cout << "Appointment successfully booked for Patient ID " << patientId << " on " << formattedDate << " at " << formattedTime << ".\n";
    }

    // Function to view all appointments with patient details
    void viewAppointments()
    {
        if (appointments.empty())
        {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "Scheduled Appointments:\n";
        for (const auto &appointment : appointments)
        {
            // Fetch patient details by patient ID
            Patient *patient = patientManager.searchPatient(appointment.patientId);
            cout << "Patient ID: " << appointment.patientId
                 << ", Name: " << (patient ? patient->name : "Unknown")
                 << ", Date: " << appointment.appointmentDate
                 << ", Time: " << appointment.appointmentTime
                 << ", Description: " << (strlen(appointment.description) == 0 ? "N/A" : appointment.description) << "\n";
        }
    }

    // Function to save appointments to a binary file
    void saveToFile(const string &filename)
    {
        ofstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error opening file for writing: " << filename << "\n";
            return;
        }

        size_t size = appointments.size();
        file.write(reinterpret_cast<const char *>(&size), sizeof(size)); // Write the number of appointments
        file.write(reinterpret_cast<const char *>(appointments.data()), size * sizeof(Appointment));

        file.close();
        cout << "Appointments saved to " << filename << " successfully.\n";
    }

    // Function to load appointments from a binary file
    void loadFromFile(const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error opening file for reading: " << filename << "\n";
            return;
        }

        size_t size;
        file.read(reinterpret_cast<char *>(&size), sizeof(size)); // Read the number of appointments

        appointments.resize(size);
        file.read(reinterpret_cast<char *>(appointments.data()), size * sizeof(Appointment));

        file.close();
        cout << "Appointments loaded from " << filename << " successfully.\n";
    }
};

#endif // APPOINTMENTMANAGEMENT_HPP
