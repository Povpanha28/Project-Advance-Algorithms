#ifndef APPOINTMENTMANAGEMENT_HPP
#define APPOINTMENTMANAGEMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Appointment class to hold appointment data
class Appointment {
public:
    int patientId;           // Patient's ID
    string appointmentTime;  // Appointment time (e.g., "2024-12-21 10:00 AM")
    string description;      // Reason for the appointment (optional)

    Appointment(int patientId, string appointmentTime, string description = "")
        : patientId(patientId), appointmentTime(appointmentTime), description(description) {}
};

class AppointmentManagement {
private:
    vector<Appointment> appointments;  // Vector to store all appointments

public:
    // Function to book an appointment for a patient
    void bookAppointment(int patientId, string appointmentTime, string description = "") {
        Appointment newAppointment(patientId, appointmentTime, description);
        appointments.push_back(newAppointment);
        cout << "Appointment booked for patient ID " << patientId << " at " << appointmentTime << endl;
    }

    // Function to cancel an appointment based on patient ID and appointment time
    void cancelAppointment(int patientId, string appointmentTime) {
        bool found = false;
        for (auto it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->patientId == patientId && it->appointmentTime == appointmentTime) {
                appointments.erase(it);  // Remove the appointment
                found = true;
                cout << "Appointment for patient ID " << patientId << " at " << appointmentTime << " has been canceled." << endl;
                break;
            }
        }
        if (!found) {
            cout << "No appointment found for patient ID " << patientId << " at " << appointmentTime << endl;
        }
    }

    // Function to reschedule an appointment
    void rescheduleAppointment(int patientId, string oldTime, string newTime) {
        bool found = false;
        for (auto& appointment : appointments) {
            if (appointment.patientId == patientId && appointment.appointmentTime == oldTime) {
                appointment.appointmentTime = newTime;  // Update the appointment time
                found = true;
                cout << "Appointment for patient ID " << patientId << " has been rescheduled from " << oldTime << " to " << newTime << endl;
                break;
            }
        }
        if (!found) {
            cout << "No appointment found for patient ID " << patientId << " at " << oldTime << endl;
        }
    }

    // Function to view all appointments
    void viewAppointments() {
        cout << "Appointments List: \n";
        if (appointments.empty()) {
            cout << "No appointments scheduled.\n";
            return;
        }
        for (const auto& appointment : appointments) {
            cout << "Patient ID: " << appointment.patientId
                 << ", Appointment Time: " << appointment.appointmentTime
                 << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
        }
    }

    // Function to search for an appointment by patient ID
    void searchAppointment(int patientId) {
        bool found = false;
        cout << "Searching for appointments for patient ID " << patientId << ":\n";
        for (const auto& appointment : appointments) {
            if (appointment.patientId == patientId) {
                cout << "Appointment Time: " << appointment.appointmentTime
                     << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No appointments found for patient ID " << patientId << endl;
        }
    }
};

#endif // APPOINTMENTMANAGEMENT_HPP
