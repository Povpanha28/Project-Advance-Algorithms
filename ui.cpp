#include <iostream>
#include <windows.h>
#include <conio.h>
#include "./utils/Appointment.hpp"
PatientManagement pm;
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
            cout<<"\tDelete Patient"<<endl;
              
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
    cout << "2. View Appointment" << endl;
    cout << "3.Back" << endl;
}
void clinic_time()
{
    cout << "\tClinic Time" << endl;
    cout << "1. Set" << endl;
    cout << "2. Views" << endl;
    cout << "3.Back" << endl;
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
        case 27:
            return 0;
        }
    }
}