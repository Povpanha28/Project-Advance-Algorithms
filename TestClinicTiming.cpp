#include <iostream>
#include "utils/timingSlot.hpp"// Ensure this is the correct relative path

int main() {
    try {
        // Create a PatientManagement object (required for Clinic constructor)
        PatientManagement patientManager; // Assuming PatientManagement is properly defined

        // Create a Clinic object
        Clinic myClinic(patientManager);

        // View default clinic hours
        std::cout << "Default clinic hours:\n";
        myClinic.viewClinicHours();

        // Update clinic hours
        std::cout << "\nUpdating clinic hours...\n";
        myClinic.setClinicHours(9, 18);

        // View updated clinic hours
        std::cout << "Updated clinic hours:\n";
        myClinic.viewClinicHours();

        // Attempt to set invalid clinic hours
        std::cout << "\nAttempting to set invalid clinic hours...\n";
        myClinic.setClinicHours(20, 6); // Invalid: Start hour is after the end hour
    }
    catch (const std::invalid_argument& e) {
        // Catch and display the error message
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

