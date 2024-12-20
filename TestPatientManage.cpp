#include <iostream> 
#include "utils/Patient_Manage.hpp"

int main() {
    PatientManagement pm;
    pm.addPatient(1,"Thyrak",19,"+855 17840285","Lonely");
    pm.addPatient(2,"Youdy",19,"+855 17840285","Lonely");
    pm.displayPatients();
    pm.deletePatient(1);
    pm.displayPatients();
    pm.editPatientDetails(2,"Panha",20,"+855 17840285","Lonely");
    pm.displayPatients();
    return 0;
}
