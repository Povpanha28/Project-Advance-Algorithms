#ifndef PATIENT_MANAGEMENT_HPP
#define PATIENT_MANAGEMENT_HPP

#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

class Patient {
public:
    int id;                
    string name;           
    int age;              
    string contact;        
    string medicalHistory; 

    Patient(int id, string name, int age, string contact, string medicalHistory) 
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

    // Add a new patient
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
};

#endif
