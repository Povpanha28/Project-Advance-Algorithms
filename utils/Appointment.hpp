#ifndef APPOINTMENTMANAGEMENT_HPP
#define APPOINTMENTMANAGEMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Appointment class to hold appointment data
class Appointment
{
public:
    int patientId;          // Patient's ID
    string appointmentDate; // Appointment Date (e.g., "2024-12-21 ")
    string appointmentTime; // Appointment time (e.g.,"10:00 AM")
    string description; // Reason for the appointment (optional)

    Appointment(int patientId, string appointmentTime, string appointmentDate, string description = "")
        : patientId(patientId), appointmentTime(appointmentTime), appointmentDate(appointmentDate), description(description) {}
};

class AppointmentManagement
{
private:
    vector<Appointment> appointments; // Vector to store all appointments

public:
    // Function to book an appointment for a patient
    void bookAppointment(int patientId, string appointmentTime, string appointmentDate, string description = "")
    {
        Appointment newAppointment(patientId, appointmentTime, appointmentDate, description);
        appointments.push_back(newAppointment);
        cout << "Appointment booked for patient ID " << patientId << " at " << appointmentTime << " " << appointmentDate << endl;
    }

    // Function to cancel an appointment based on patient ID and appointment time
    void cancelAppointment(int patientId, string appointmentTime, string appointmentDate)
    {
        bool found = false;
        for (auto it = appointments.begin(); it != appointments.end(); ++it)
        {
            if (it->patientId == patientId && it->appointmentTime == appointmentTime && it->appointmentDate == appointmentDate)
            {
                appointments.erase(it); // Remove the appointment
                found = true;
                cout << "Appointment for patient ID " << patientId << " at " << appointmentTime << " " << appointmentDate << " has been canceled." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "No appointment found for patient ID " << patientId << " at " << appointmentTime << " " << appointmentDate << endl;
        }
    }

    // Function to reschedule an appointment
    void rescheduleAppointment(int patientId, string oldTime, string oldDate, string newTime, string newDate)
    {
        bool found = false;
        for (auto &appointment : appointments)
        {
            if (appointment.patientId == patientId && appointment.appointmentTime == oldTime && appointment.appointmentDate == oldDate)
            {
                appointment.appointmentTime = newTime; // Update the appointment time
                appointment.appointmentDate = newDate; // Update the appointment date
                found = true;
                cout << "Appointment for patient ID " << patientId << " has been rescheduled from " << oldTime << " " << oldDate << " to " << newTime << " " << newDate << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "No appointment found for patient ID " << patientId << " at " << oldTime << " " << oldDate << endl;
        }
    }

    // Function to view all appointments
    void viewAppointments()
    {
        cout << "Appointments List: \n";
        if (appointments.empty())
        {
            cout << "No appointments scheduled.\n";
            return;
        }
        for (const auto &appointment : appointments)
        {
            cout << "Patient ID: " << appointment.patientId
                 << ", Appointment Time: " << appointment.appointmentTime
                 << ", Appointment Date: " << appointment.appointmentDate
                 << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
        }
    }

    // Function to search for an appointment by patient ID
    void searchAppointment(int patientId)
    {
        bool found = false;
        cout << "Searching for appointments for patient ID " << patientId << ":\n";
        for (const auto &appointment : appointments)
        {
            if (appointment.patientId == patientId)
            {
                cout << "Appointment Time: " << appointment.appointmentTime
                     << ", Appointment Date: " << appointment.appointmentDate
                     << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No appointments found for patient ID " << patientId << endl;
        }
    }

    void generateAppointmentReport()
    {
        if (appointments.empty())
        {
            cout << "No appointments available.\n";
            return;
        }

        // Variables to hold the maximum width of each column
        size_t maxIdWidth = 10;   // Minimum width for Patient ID
        size_t maxTimeWidth = 20; // Minimum width for Appointment Time
        size_t maxDescWidth = 12; // Minimum width for Description

        // Calculate the maximum width of each column
        for (const auto &appointment : appointments)
        {
            maxIdWidth = std::max(maxIdWidth, std::to_string(appointment.patientId).length());
            maxTimeWidth = std::max(maxTimeWidth, appointment.appointmentTime.length());
            maxDescWidth = std::max(maxDescWidth, appointment.description.length());
        }

        // Generate the header and separator line
        cout << "Appointment Report\n";
        size_t lineLength = maxIdWidth + maxTimeWidth + maxDescWidth + 12;
        for (size_t i = 0; i < lineLength; ++i)
            cout << "-";
        cout << "\n";

        // Print the column headers with dynamic widths
        cout << left << setw(maxIdWidth + 2) << "Patient ID"
             << setw(maxTimeWidth + 2) << "Appointment Time"
             << setw(maxDescWidth + 2) << "Description" << endl;

        for (size_t i = 0; i < lineLength; ++i)
            cout << "-";
        cout << "\n";

        // Print the appointment data with dynamic widths
        for (const auto &appointment : appointments)
        {
            cout << left << setw(maxIdWidth + 2) << appointment.patientId
                 << setw(maxTimeWidth + 2) << appointment.appointmentTime
                 << setw(maxDescWidth + 2) << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
        }

        for (size_t i = 0; i < lineLength; ++i)
            cout << "-";
        cout << "\n";
    }
};

#endif // APPOINTMENTMANAGEMENT_HPP
