#include <iostream>
#include "utils/Patient_Manage.hpp"

int main()
{
    // Create an instance of PatientManagement
    PatientManagement pm;
    string pm_file="file/pm.dat";

    // Add some patients
    // pm.addPatient(1, "Alice", 30, "123-456-7890", "None");
    // pm.addPatient(2, "Bob", 45, "987-654-3210", "Diabetes");
   
    // pm.saveToFile("pm_file");

    pm.loadFromFile("pm_file");
    //Display patients
    pm.displayPatients();

    // pm.editPatientDetails(1, "Alice", 30, "123-456-7890", "Chir");
    // pm.saveToFile("pm_file");

    // pm.loadFromFile("pm_file");
    // // Display patients
    // pm.displayPatients();
    return 0;
}
