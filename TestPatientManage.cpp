#include <iostream>
#include "Patient_Manage.hpp"

int main() {
    // Create an instance of PatientManagement
    PatientManagement patientManager;

    // Test 1: Add patients
    patientManager.addPatient(1, "John Doe", 30, "555-1234", "None");
    patientManager.addPatient(2, "Jane Smith", 28, "555-5678", "Asthma");
    patientManager.addPatient(3, "Alice Johnson", 35, "555-8765", "Diabetes");
    patientManager.addPatient(4, "Bob Brown", 40, "555-4321", "None");

    // Test 2: Display all patients
    std::cout << "Displaying all patients:\n";
    patientManager.displayPatients();
    std::cout << "\n";

    // Test 3: Search for a patient by ID
    int searchId = 2;
    std::cout << "Searching for patient with ID " << searchId << ":\n";
    Patient* patient = patientManager.searchPatient(searchId);
    if (patient != nullptr) {
        std::cout << "Found patient: " << patient->name << ", Age: " << patient->age << std::endl;
    } else {
        std::cout << "Patient not found.\n";
    }
    std::cout << "\n";

    // Test 4: Edit patient details
    patientManager.editPatientDetails(3, "Alice Johnson", 36, "555-9999", "Diabetes, Hypertension");

    // Test 5: Display all patients again after editing
    std::cout << "Displaying all patients after editing:\n";
    patientManager.displayPatients();
    std::cout << "\n";

    // Test 6: Delete a patient
    patientManager.deletePatient(1);

    // Test 7: Display all patients after deletion
    std::cout << "Displaying all patients after deletion:\n";
    patientManager.displayPatients();
    std::cout << "\n";

    return 0;
}
