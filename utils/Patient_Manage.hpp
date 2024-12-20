#ifndef PATIENT_MANAGEMENT_HPP
#define PATIENT_MANAGEMENT_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
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

    void generatePatientReport() {
        if (head == nullptr) {
            cout << "No patients available.\n";
            return;
        }

        // Variables to hold the maximum width of each column
        size_t maxIdWidth = 2;  // Minimum width for ID is 2 (for single-digit IDs like 1, 2)
        size_t maxNameWidth = 4; // Minimum width for Name, this is dynamic
        size_t maxAgeWidth = 3;  // Minimum width for Age (e.g., 100 for age, but may vary)
        size_t maxContactWidth = 7; // Minimum width for Contact (can vary based on format)
        size_t maxHistoryWidth = 15; // Minimum width for Medical History

        PatientNode* temp = head;

        // Find the maximum width for each column based on the data
        while (temp != nullptr) {
            maxIdWidth = max(maxIdWidth, to_string(temp->data.id).length());
            maxNameWidth = max(maxNameWidth, temp->data.name.length());
            maxAgeWidth = max(maxAgeWidth, to_string(temp->data.age).length());
            maxContactWidth = max(maxContactWidth, temp->data.contact.length());
            maxHistoryWidth = max(maxHistoryWidth, temp->data.medicalHistory.length());

            temp = temp->next;
        }

        // Generate the header and separator line with dynamic widths
        cout << "Patient Report\n";
        size_t lineLength = maxIdWidth + maxNameWidth + maxAgeWidth + maxContactWidth + maxHistoryWidth + 13;
        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";

        // Print the column headers with dynamic widths
        cout << left << setw(maxIdWidth + 2) << "ID"
            << setw(maxNameWidth + 2) << "Name"
            << setw(maxAgeWidth + 2) << "Age"
            << setw(maxContactWidth + 2) << "Contact"
            << setw(maxHistoryWidth + 2) << "Medical History" << endl;

        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";

        // Print the patient data with dynamic widths
        temp = head;
        while (temp != nullptr) {
            cout << left << setw(maxIdWidth + 2) << temp->data.id
                << setw(maxNameWidth + 2) << temp->data.name
                << setw(maxAgeWidth + 2) << temp->data.age
                << setw(maxContactWidth + 2) << temp->data.contact
                << setw(maxHistoryWidth + 2) << temp->data.medicalHistory << endl;
            temp = temp->next;
        }

        for (size_t i = 0; i < lineLength; ++i) cout << "-";
        cout << "\n";
    }

    void generateCSVReport() {
        if (head == nullptr) {
            cout << "No patients available.\n";
            return;
        }

        ofstream reportFile("patient_report.csv");
        if (!reportFile.is_open()) {
            cout << "Error opening file for report generation.\n";
            return;
        }

        // Write the headers
        reportFile << "ID,Name,Age,Contact,Medical History\n";

        PatientNode* temp = head;
        while (temp != nullptr) {
            reportFile << temp->data.id << ","
                    << temp->data.name << ","
                    << temp->data.age << ","
                    << temp->data.contact << ","
                    << temp->data.medicalHistory << "\n";
            temp = temp->next;
        }

        reportFile.close();
        cout << "Report saved to 'patient_report.csv'.\n";
    }

    void generateSummaryReport() {
        if (head == nullptr) {
            cout << "No patients available.\n";
            return;
        }

        int totalPatients = 0;
        int totalAge = 0;

        PatientNode* temp = head;
        while (temp != nullptr) {
            totalPatients++;
            totalAge += temp->data.age;
            temp = temp->next;
        }

        double averageAge = totalPatients > 0 ? static_cast<double>(totalAge) / totalPatients : 0;

        cout << "Patient Summary Report\n";
        cout << "---------------------------------\n";
        cout << "Total Patients: " << totalPatients << "\n";
        cout << "Average Age: " << averageAge << "\n";
        cout << "---------------------------------\n";
    }
};

#endif
