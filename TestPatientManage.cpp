#include <iostream>
#include "utils/Patient_Manage.hpp"

int main()
{
    // Create an instance of PatientManagement
    PatientManagement pm;

    // Add some patients
    pm.addPatient(1, "Alice", 30, "123-456-7890", "None");
    pm.addPatient(2, "Bob", 45, "987-654-3210", "Diabetes");

    pm.saveToFile("file/PatientInfo.dat");

    pm.loadFromFile("file/PatientInfo.dat");
    // Display patients
    pm.displayPatients();

    pm.editPatientDetails(1, "Alice", 30, "123-456-7890", "Chir");
    pm.saveToFile("file/PatientInfo.dat");

    pm.loadFromFile("file/PatientInfo.dat");
    // Display patients
    pm.displayPatients();
    return 0;
}
