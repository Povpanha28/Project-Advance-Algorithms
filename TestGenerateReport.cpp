#include <iostream>
#include <string>
#include "utils/Patient_Manage.hpp"
#include "utils/Appointment.hpp"
#include "utils/Generate.hpp"

int main() {
    // Create an instance of PatientManagement
    PatientManagement patientManager;

    // Adding some patients to the system
    patientManager.addPatient(1, "John Doe", 30, "555-1234", "None");
    patientManager.addPatient(2, "Jane Smith", 28, "555-5678", "Asthma");
    patientManager.addPatient(3, "Alice Johnson", 35, "555-8765", "Diabetes");

    // Create an instance of AppointmentManagement linked to the patient manager
    AppointmentManagement appointmentManager(patientManager);

    // Book appointments for the patients
    cout << "Booking appointments for patients...\n";
    appointmentManager.bookAppointment(); // Book appointment for patient 1

    // Display the list of all appointments
    cout << "\nViewing all appointments:\n";
    appointmentManager.viewAppointments();

    // Generate the patient report with appointment details
    cout << "\nGenerating Patient Report...\n";
    PatientReport::displayPatientReport(patientManager, appointmentManager);

    return 0;
}