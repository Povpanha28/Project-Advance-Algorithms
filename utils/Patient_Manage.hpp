#ifndef PATIENT_MANAGEMENT_HPP
#define PATIENT_MANAGEMENT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp" // Assuming Node.hpp contains the Patient and PatientNode definitions

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string contact;
    string medicalHistory;

    Patient(int id = 0, string name = "", int age = 0, string contact = "", string medicalHistory = "") 
        : id(id), name(name), age(age), contact(contact), medicalHistory(medicalHistory) {}
};

class PatientNode {
public:
    Patient data;
    PatientNode* next;

    PatientNode(Patient patient) : data(patient), next(nullptr) {}
};

class PatientManagement {
private:
    PatientNode* head;
    int patientCount;

public:
    // Constructor
    PatientManagement() : head(nullptr), patientCount(0) {}

    // Destructor to clean up memory
    ~PatientManagement() {
        while (head != nullptr) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient(int id, string name, int age, string contact, string medicalHistory) {
        Patient newPatient(id, name, age, contact, medicalHistory);
        PatientNode* newNode = new PatientNode(newPatient);

        if (head == nullptr) {
            head = newNode;
        } else {
            PatientNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        patientCount++;
        cout << "Patient added successfully.\n";
    }

    Patient* searchPatient(int id) {
        PatientNode* temp = head;
        while (temp != nullptr) {
            if (temp->data.id == id) {
                return &temp->data;
            }
            temp = temp->next;
        }
        return nullptr; // Patient not found
    }

    void editPatientDetails(int id, string name, int age, string contact, string medicalHistory) {
        Patient* patient = searchPatient(id);
        if (patient != nullptr) {
            patient->name = name;
            patient->age = age;
            patient->contact = contact;
            patient->medicalHistory = medicalHistory;
            cout << "Patient details updated successfully.\n";
        } else {
            cout << "Patient not found.\n";
        }
    }

    void deletePatient(int id) {
        if (head == nullptr) {
            cout << "No patients to delete.\n";
            return;
        }

        if (head->data.id == id) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
            patientCount--;
            cout << "Patient deleted successfully.\n";
            return;
        }

        PatientNode* current = head;
        PatientNode* prev = nullptr;

        while (current != nullptr && current->data.id != id) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Patient not found.\n";
        } else {
            prev->next = current->next;
            delete current;
            patientCount--;
            cout << "Patient deleted successfully.\n";
        }
    }

    void displayPatients() {
        if (head == nullptr) {
            cout << "No patients available.\n";
            return;
        }

        PatientNode* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->data.id
                 << ", Name: " << temp->data.name
                 << ", Age: " << temp->data.age
                 << ", Contact: " << temp->data.contact
                 << ", Medical History: " << temp->data.medicalHistory << endl;
            temp = temp->next;
        }
    }

    int getPatientCount() {
        return patientCount;
    }

    PatientNode* getHead() {
        return head; // To be used by PatientReport
    }

    // Save patients to a file
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing.\n";
            return;
        }

        PatientNode* temp = head;
        while (temp != nullptr) {
            file << temp->data.id << ","
                 << temp->data.name << ","
                 << temp->data.age << ","
                 << temp->data.contact << ","
                 << temp->data.medicalHistory << endl;
            temp = temp->next;
        }

        file.close();
        cout << "Patients saved to file successfully.\n";
    }

    // Load patients from a file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading.\n";
            return;
        }

        // Clear existing patients
        while (head != nullptr) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
        patientCount = 0;

        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            string token;
            int id, age;
            string name, contact, medicalHistory;

            // Extract data fields
            pos = line.find(",");
            id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            age = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            contact = line.substr(0, pos);
            line.erase(0, pos + 1);

            medicalHistory = line;

            // Add patient to the list
            addPatient(id, name, age, contact, medicalHistory);
        }

        file.close();
        cout << "Patients loaded from file successfully.\n";
    }
};

#endif // PATIENT_MANAGEMENT_HPP
