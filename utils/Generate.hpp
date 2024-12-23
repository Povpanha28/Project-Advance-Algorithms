#ifndef PATIENT_REPORT_HPP
#define PATIENT_REPORT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Patient_Manage.hpp" // Include the PatientManagement class
#include "Appointment.hpp" // Include AppointmentManagement to access appointments

using namespace std;

class PatientReport {
public:
    // Function to display all patient reports along with their appointment details
    static void displayPatientReport(PatientManagement& patientManagement, AppointmentManagement& appointmentManagement) {
        PatientNode* head = patientManagement.getHead(); // Access the head of the list
        if (head == nullptr) {
            cout << "No patients available.\n";
            return;
        }

        // Define minimum column widths
        size_t maxIdWidth = 2, maxNameWidth = 4, maxAgeWidth = 3;
        size_t maxContactWidth = 7, maxHistoryWidth = 15;

        // Determine the maximum width for each column based on the data
        PatientNode* temp = head;
        while (temp != nullptr) {
            maxIdWidth = max(maxIdWidth, to_string(temp->data.id).length());
            maxNameWidth = max(maxNameWidth, temp->data.name.length());
            maxAgeWidth = max(maxAgeWidth, to_string(temp->data.age).length());
            maxContactWidth = max(maxContactWidth, temp->data.contact.length());
            maxHistoryWidth = max(maxHistoryWidth, temp->data.medicalHistory.length());

            temp = temp->next;
        }

        // Print the report header
        cout << "Patient Report\n";
        size_t lineLength = maxIdWidth + maxNameWidth + maxAgeWidth + maxContactWidth + maxHistoryWidth + 13;
        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";

        // Print the column headers with dynamic widths
        cout << left << setw(maxIdWidth + 2) << "ID"
             << setw(maxNameWidth + 2) << "Name"
             << setw(maxAgeWidth + 2) << "Age"
             << setw(maxContactWidth + 2) << "Contact"
             << setw(maxHistoryWidth + 2) << "Medical History" << endl;

        // Print the separator line
        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";

        // Print the patient details along with their appointment details
        temp = head;
        while (temp != nullptr) {
            cout << left << setw(maxIdWidth + 2) << temp->data.id
                 << setw(maxNameWidth + 2) << temp->data.name
                 << setw(maxAgeWidth + 2) << temp->data.age
                 << setw(maxContactWidth + 2) << temp->data.contact
                 << setw(maxHistoryWidth + 2) << temp->data.medicalHistory;

            // Fetch the appointment details for the current patient
            bool hasAppointments = false;
            for (const auto &appointment : appointmentManagement.appointments){
                if (appointment.patientId == temp->data.id) {
                    hasAppointments = true;
                    cout << " | Appointment: " << appointment.appointmentDate 
                         << " at " << appointment.appointmentTime
                         << ", Description: " << (appointment.description.empty() ? "N/A" : appointment.description) << endl;
                }
            }

            if (!hasAppointments) {
                cout << " | No appointments.\n";
            }

            temp = temp->next;
        }

        // Print the footer line
        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";
    }
};


#endif // PATIENT_REPORT_HPP
