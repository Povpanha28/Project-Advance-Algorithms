#include <iostream>
#include "utils/Appointment.hpp"
#include "utils/Patient_Manage.hpp"


int main()
{
    // Create PatientManagement and AppointmentManagement instances
    PatientManagement patientManager;
    AppointmentManagement appointmentManager(patientManager);

    // Add test patients
    cout << "\nAdding test patients...\n";
    patientManager.addPatient(1, "John Doe", 30, "123456789", "Diabetes");
    patientManager.addPatient(2, "Jane Smith", 25, "987654321", "Allergy");

    // Display patients to confirm addition
    cout << "\nDisplaying all patients:\n";
    patientManager.displayPatients();

    // Book appointments for the patients
    cout << "\nBooking appointments for patients...\n";
    appointmentManager.bookAppointment();
    appointmentManager.bookAppointment();

    // View all appointments
    cout << "\nViewing all appointments:\n";
    appointmentManager.viewAppointments();

    // Edit an appointment
    cout << "\nEditing appointment for Patient ID 1...\n";
    appointmentManager.editAppointment();

    // View all appointments after edit
    cout << "\nViewing all appointments after edit:\n";
    appointmentManager.viewAppointments();

    // Delete an appointment
    cout << "\nDeleting appointment for Patient ID 2...\n";
    appointmentManager.deleteAppointment();

    // View all appointments after deletion
    cout << "\nViewing all appointments after deletion:\n";
    appointmentManager.viewAppointments();

    // Save appointments to a binary file
    string appointmentFilename = "appointments.dat";
    cout << "\nSaving appointments to binary file...\n";
    appointmentManager.saveToFile(appointmentFilename);

    // Clear appointments and reload from file
    cout << "\nClearing all appointments in memory...\n";
    appointmentManager.loadFromFile(appointmentFilename);

    // View all appointments after reloading
    cout << "\nViewing all appointments after reloading from file:\n";
    appointmentManager.viewAppointments();

    return 0;
}
