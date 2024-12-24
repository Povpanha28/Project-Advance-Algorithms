#include <iostream>
#include "utils/Appointment.hpp"
#include "utils/Patient_Manage.hpp"
string pmfile="file/PatientInfo.dat";
string amfile="file/appointment.dat";
PatientManagement pm;
AppointmentManagement am(pm);

int main(){
    
    // pm.addPatient(1,"jkj",12,"42342342","none");
    // pm.saveToFile("pmfile");
    pm.loadFromFile("pmfile");
    pm.displayPatients();
    // am.bookAppointment();
    // am.saveToFile("amfile");
    // am.deleteAppointment();
    // am.saveToFile("amfile");
    // pm.deletePatient(1);
    // pm.saveToFile("pmfile");
    
}