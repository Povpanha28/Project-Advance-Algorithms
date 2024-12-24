#include <iostream>
#include <windows.h>
#include <conio.h>
#include "utils/Appointment.hpp"
#include "utils/Patient_Manage.hpp"
#include "utils/Generate.hpp"

string PM_file="file/PatientInfo.dat";
string APM_file="file/appointment.dat";

PatientManagement pm;
AppointmentManagement app_m(pm);

using namespace std;
void initial(){
    pm.loadFromFile("PM_file");
    app_m.loadFromFile("APM_file");
}
void closing(){
    pm.saveToFile("PM_file");
    app_m.saveToFile("APM_file");
}
void header()
{
    cout << "\tClinic Management" << endl;
    cout << "1. Patient Management" << endl;
    cout << "2. Appointment Management" << endl;
    cout << "3. Clinic Time" << endl;
    cout << "4. Generate Report" << endl;
    cout << "Esc to Exit" << endl;
}
void patient_management()
{
    
        home:
        system("cls");
        cout << "\t Patient Managent" << endl;
        cout << "1. New Patient" << endl;
        cout << "2. Display Patient" << endl;
        cout << "3. Update Patient Info" << endl;
        cout << "4. Delete" << endl;
        cout << "ESC to Back" << endl;
        while (true){
        char option = getch();
        switch (option)
        {
        case '1':{
            system("cls");
            int id, age;
            string name, tel, Mrecord;
            cout << "\tNew Patient" << endl;
            cout << "Enter ID :";
            cin >> id;
            cin.ignore();
            cout << "Enter Name:";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter Phone Number:";
            getline(cin, tel);
            cout << "Medical Record: ";
            getline(cin, Mrecord);
            system("cls");
            pm.addPatient(id, name, age, tel, Mrecord);
            cout << "\nPatient added successfully.\n";
            cout<<endl<<"Press ENTER to go back";
            break;
        }
        case '2':{
            system("cls");
            cout << "Display Patient" << endl;
            pm.displayPatients();
            cout<<endl<<"Press ENTER to go back";
            break;
        }
        case '3':{
            system("cls");
            int ID;
            cout << "\tUpdate Patient Info" << endl;
            cout << "Enter Patient ID: ";
            cin >> ID;
            

            Patient *patient = pm.searchPatient(ID);
            if (patient == nullptr)
            {
                cout << "Patient with ID " << ID << " not found.\n";
            }
            else{
                cout<<"Patient Found!!";
                pm.displayPatientById(ID);
            }
            cout<<endl<<"Which do you want to Update?"<<endl;
            cout << "1. Update ID" << endl
                 << "2. Update Name" << endl
                 << "3. Update Age" << endl
                 << "4. Update Contact" << endl
                 << "5. Update Medical Record" << endl
                 << "Esc to Back"<<endl;

            char choice = getch();
            switch (choice){
                case '1':{
                    system("cls");
                    pm.displayPatientById(ID);
                    int newId;
                    cout << "Enter new ID: ";
                    cin >> newId;
                    patient->id = newId;
                    cout << "ID updated successfully."<<endl;

                    break;
                }
                case '2':{
                    system("cls");
                    pm.displayPatientById(ID);
                    string newName;
                    cout << "Enter new Name: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newName);
                    patient->name = newName;
                    cout << "Name updated successfully."<<endl;
                    break;
                }
                case '3':{
                    system("cls");
                    pm.displayPatientById(ID);
                    int newAge;
                    cout << "Enter new Age: ";
                    cin >> newAge;
                    patient->age = newAge;
                    cout << "Age updated successfully."<<endl;
                    break;
                }
                case '4':{
                    system("cls");
                    pm.displayPatientById(ID);
                    string newContact;
                    cout << "Enter new Contact: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newContact);
                    patient->contact = newContact;
                    cout << "Contact updated successfully."<<endl;
                    break;
                }
                case '5':{
                    system("cls");
                    pm.displayPatientById(ID);
                    string newMedicalHistory;
                    cout << "Enter new Medical History: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newMedicalHistory);
                    patient->medicalHistory = newMedicalHistory;
                    break;
                }
                case 27:{
                    return;
                }
                }
            cout<<endl<<"Press ENTER to go back";
            break;
        }
        case '4':{
            int id;
            char choice;
            system("cls");
            cout<<"\tDelete Patient"<<endl;
            cout<<"Enter ID: ";
            cin>>id;
            pm.displayPatientById(id);
            cout<<endl<<"Are You Sure To Delete This Patient? y/n :";
            cin>>choice;
            if(choice=='y'||choice=='Y'){
                pm.deletePatient(id);
            }
            cout<<endl<<"Press ENTER to go back";
            break;
        }
        case 13:{
            goto home;
            break;
        }
        case 27:
            return;
            break;
        }
    }
}
void app_management()
{
    home:
    system("cls");
    cout << "\tAppointment Management" << endl;
    cout << "1. Make Appointment" << endl;
    cout << "2. Update Appointment"<<endl;
    cout << "3. View Appointment" << endl;
    cout << "4. Delete Appointment"<<endl;
    cout << "ESC to Back" << endl;
   while(true){
    char option=getch();
        switch (option){
            case '1':{
                system("cls");
                cout<<"\tMake Appointment"<<endl;
                app_m.bookAppointment();
                cout<<endl<<"Press ENTER to go back";
                break;
            }
            case '2':{
                system("cls");
                cout<<"\t Update Appiontment"<<endl;
                app_m.editAppointment();
                cout<<endl<<"Press ENTER to go back";
                break;
            }
            case '3':{
                system("cls");
                cout<<"\tView Appointment"<<endl;
                app_m.viewAppointments();
                cout<<endl<<"Press ENTER to go back";
                break;
            }
            case '4':{
                system("cls");
                app_m.deleteAppointment();
                cout<<endl<<"Press ENTER to go back";
                break;
            }
            case 27:{
                return;
                break;
            }
            case 13:{
                goto home;
                break;
            }
            default:{
                cout<<endl<<"Invalid Input!!"<<endl;
                break;
            }
                
            }
    }
}
void clinic_time()
{
    cout << "\tClinic Time" << endl;
    cout << "1. Set" << endl;
    cout << "2. Views" << endl;
    cout << "3.Back" << endl;
}
void generateReport(){
    system("cls");
    cout << "\nGenerating Patient Report";
    for(int i=0;i<3;i++){
        cout<<".";
        Sleep(500);}
    system("cls");
    cout<<"\t";
    PatientReport::displayPatientReport(pm,app_m);
    cout<<endl<<"Press ENTER to go back";
    while(true){
        char option=getch();
        if(option==13){
            return;
        }
    }
    
    
}
int main(){
    system("cls");
    initial();
    Sleep(2000);
    while (true)
    {
        system("cls");
        header();
        char option = getch();
        switch (option)
        {
        case '1':
            patient_management();
            break;
        case '2':
            app_management();
            break;
        case '3':
            clinic_time();
            break;
        case '4':
            generateReport();
            break;
        case 27:
            closing();
            system("cls");
            cout<<"Program Ended";
            return 0;
        default:{
            system("cls");
            cout<<"Invalid Input";
            Sleep(500);
        }
        }
    }
}