#ifndef PATIENT_MANAGEMENT_HPP
#define PATIENT_MANAGEMENT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp"

using namespace std;

class Patient
{
public:
    int id;
    string name;
    int age;
    string contact;
    string medicalHistory;

    Patient(int id = 0, string name = "", int age = 0, string contact = "", string medicalHistory = "")
        : id(id), name(name), age(age), contact(contact), medicalHistory(medicalHistory) {}
};

class PatientNode
{
public:
    Patient data;
    PatientNode *next;

    PatientNode(Patient patient) : data(patient), next(nullptr) {}
};

class PatientManagement
{
private:
    PatientNode *head;
    int patientCount;

public:
    // Constructor
    PatientManagement() : head(nullptr), patientCount(0) {}

    // Destructor to clean up memory
    ~PatientManagement()
    {
        while (head != nullptr)
        {
            PatientNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient(int id, string name, int age, string contact, string medicalHistory)
    {
        Patient newPatient(id, name, age, contact, medicalHistory);
        PatientNode *newNode = new PatientNode(newPatient);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            PatientNode *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        patientCount++;
        
    }

    Patient *searchPatient(int id)
    {
        PatientNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->data.id == id)
            {
                return &temp->data;
            }
            temp = temp->next;
        }
        return nullptr; // Patient not found
    }

    void editPatientDetails(int id, string name, int age, string contact, string medicalHistory)
    {
        Patient *patient = searchPatient(id);
        if (patient != nullptr)
        {
            patient->name = name;
            patient->age = age;
            patient->contact = contact;
            patient->medicalHistory = medicalHistory;
            cout << "Patient details updated successfully.\n";
        }
        else
        {
            cout << "Patient not found.\n";
        }
    }

    void deletePatient(int id)
    {
        if (head == nullptr)
        {
            cout << "No patients to delete.\n";
            return;
        }

        if (head->data.id == id)
        {
            PatientNode *temp = head;
            head = head->next;
            delete temp;
            patientCount--;
            cout << "Patient deleted successfully.\n";
            return;
        }

        PatientNode *current = head;
        PatientNode *prev = nullptr;

        while (current != nullptr && current->data.id != id)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Patient not found.\n";
        }
        else
        {
            prev->next = current->next;
            delete current;
            patientCount--;
            cout << "Patient deleted successfully.\n";
        }
    }

    void displayPatients()
    {
        if (head == nullptr)
        {
            cout << "No patients available.\n";
            return;
        }

        PatientNode *temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->data.id
                 << ", Name: " << temp->data.name
                 << ", Age: " << temp->data.age
                 << ", Contact: " << temp->data.contact
                 << ", Medical History: " << temp->data.medicalHistory << endl;
            temp = temp->next;
        }
    }

    int getPatientCount()
    {
        return patientCount;
    }

    PatientNode *getHead()
    {
        return head; // To be used by PatientReport
    }

    // Save patients to a file
    // Save patients to a binary file
    void saveToFile(const string &filename)
    {
        ofstream file(filename, ios::binary);
        if (!file.is_open())
        {
            cout << "Error opening file for writing.\n";
            return;
        }

        PatientNode *temp = head;
        while (temp != nullptr)
        {
            file.write(reinterpret_cast<const char *>(&temp->data.id), sizeof(temp->data.id));
            file.write(reinterpret_cast<const char *>(&temp->data.age), sizeof(temp->data.age));

            size_t nameSize = temp->data.name.size();
            size_t contactSize = temp->data.contact.size();
            size_t medicalHistorySize = temp->data.medicalHistory.size();

            file.write(reinterpret_cast<const char *>(&nameSize), sizeof(nameSize));
            file.write(temp->data.name.c_str(), nameSize);

            file.write(reinterpret_cast<const char *>(&contactSize), sizeof(contactSize));
            file.write(temp->data.contact.c_str(), contactSize);

            file.write(reinterpret_cast<const char *>(&medicalHistorySize), sizeof(medicalHistorySize));
            file.write(temp->data.medicalHistory.c_str(), medicalHistorySize);

            temp = temp->next;
        }

        file.close();
        cout << "Patients saved to file successfully.\n";
    }

    // Load patients from a binary file
    void loadFromFile(const string &filename)
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error opening file for reading.\n";
            return;
        }

        // Clear existing patients
        while (head != nullptr)
        {
            PatientNode *temp = head;
            head = head->next;
            delete temp;
        }
        patientCount = 0;

        while (!file.eof())
        {
            Patient tempPatient;

            if (!file.read(reinterpret_cast<char *>(&tempPatient.id), sizeof(tempPatient.id)))
                break;
            file.read(reinterpret_cast<char *>(&tempPatient.age), sizeof(tempPatient.age));

            size_t nameSize, contactSize, medicalHistorySize;

            file.read(reinterpret_cast<char *>(&nameSize), sizeof(nameSize));
            char *nameBuffer = new char[nameSize + 1];
            file.read(nameBuffer, nameSize);
            nameBuffer[nameSize] = '\0';
            tempPatient.name = nameBuffer;
            delete[] nameBuffer;

            file.read(reinterpret_cast<char *>(&contactSize), sizeof(contactSize));
            char *contactBuffer = new char[contactSize + 1];
            file.read(contactBuffer, contactSize);
            contactBuffer[contactSize] = '\0';
            tempPatient.contact = contactBuffer;
            delete[] contactBuffer;

            file.read(reinterpret_cast<char *>(&medicalHistorySize), sizeof(medicalHistorySize));
            char *medicalHistoryBuffer = new char[medicalHistorySize + 1];
            file.read(medicalHistoryBuffer, medicalHistorySize);
            medicalHistoryBuffer[medicalHistorySize] = '\0';
            tempPatient.medicalHistory = medicalHistoryBuffer;
            delete[] medicalHistoryBuffer;

            addPatient(tempPatient.id, tempPatient.name, tempPatient.age, tempPatient.contact, tempPatient.medicalHistory);
        }

        file.close();
        cout << "Patients loaded from file successfully.\n";
    }

    void displayPatientById(int id)
    {
        Patient *patient = searchPatient(id);
        if (patient != nullptr)
        {
            cout << "Patient Details:\n";
            cout << "---------------------------------\n";
            cout << "ID: " << patient->id << "\n";
            cout << "Name: " << patient->name << "\n";
            cout << "Age: " << patient->age << "\n";
            cout << "Contact: " << patient->contact << "\n";
            cout << "Medical History: " << patient->medicalHistory << "\n";
            cout << "---------------------------------\n";
        }
        else
        {
            cout << "Patient with ID " << id << " not found.\n";
        }
    }
};

#endif // PATIENT_MANAGEMENT_HPP
