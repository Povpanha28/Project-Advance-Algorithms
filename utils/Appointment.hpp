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
    string appointmentDate; // Appointment Date (e.g., "2024-12-21")
    string appointmentTime; // Appointment Time (e.g., "10:00")
    string description;     // Reason for the appointment (optional)

    Appointment(int patientId = 0, string appointmentDate = "", string appointmentTime = "", string description = "")
        : patientId(patientId), appointmentDate(appointmentDate), appointmentTime(appointmentTime), description(description) {}
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
                 << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << "\n";
        }
    }
    void editAppointment()
    {
        int patientId, newYear, newMonth, newDay, newHour, newMinute;
        string newDescription;

        cout << "Enter Patient ID: ";
        cin >> patientId;
    }
};