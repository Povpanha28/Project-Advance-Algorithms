#include <iostream>
#include <windows.h>
#include <conio.h>
#include "utils/Appointment.hpp"
#include "utils/Patient_Manage.hpp"


PatientManagement pm;
AppointmentManagement app_m(pm);

using namespace std;

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
    while (true)
    {

        cout << "\t Patient Managent" << endl;
        cout << "1. New Patient" << endl;
        cout << "2. Display Patient" << endl;
        cout << "3. Update Patient Info" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Back" << endl;
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
            pm.addPatient(id, name, age, tel, Mrecord);
            break;
        }
        case '2':{
            system("cls");
            cout << "Display Patient" << endl;
            pm.displayPatients();
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
                 << "2.Update Name" << endl
                 << "3. Update Age" << endl
                 << "4. Update Contact" << endl
                 << "5. Update Medical Record" << endl
                 << "Esc to Back";

            char choice = getch();
            switch (choice){
                case '1':{
                     int newId;
                    cout << "Enter new ID: ";
                    cin >> newId;
                    patient->id = newId;
                    cout << "ID updated successfully."<<endl;

                    break;
                }
                case '2':{
                    string newName;
                    cout << "Enter new Name: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newName);
                    patient->name = newName;
                    cout << "Name updated successfully."<<endl;
                    break;
                }
                case '3':{
                    int newAge;
                    cout << "Enter new Age: ";
                    cin >> newAge;
                    patient->age = newAge;
                    cout << "Age updated successfully."<<endl;
                    break;
                }
                case '4':{
                    string newContact;
                    cout << "Enter new Contact: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newContact);
                    patient->contact = newContact;
                    cout << "Contact updated successfully."<<endl;
                    break;
                }
                case '5':{
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
                break;
        }
        case '4':{
            int id;
            char choice;
            cout<<"\tDelete Patient"<<endl;
            cout<<"Enter ID: ";
            cin>>id;
            pm.displayPatientById(id);
            cout<<endl<<"Are You Sure To Delete This Patient? y/n :";
            cin>>choice;
            if(choice=='y'||choice=='Y'){
                pm.deletePatient(id);
                cout<<"Successfully Delete"<<endl;
            }
            break;
        }
        case '5':
            return;
            break;
        }
    }
}
void app_management()
{
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
                break;
            }
            case '2':{
                system("cls");
                cout<<"\t Update Appiontment"<<endl;
                app_m.editAppointment();
                break;
            }
            case '3':{
                system("cls");
                cout<<"\tView Appointment"<<endl;
                app_m.viewAppointments();
                break;
            }
            case '4':{
                system("cls");
                app_m.deleteAppointment();
                break;
            }
            case 27:{
                return;
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
    
}
int main()
{
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
            return 0;
        default:{
            system("cls");
            cout<<"Invalid Input";
            Sleep(500);
        }
        }
    }
}