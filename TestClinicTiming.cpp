#include "utils/timingSlot.hpp"

int main() {
    try {
        // Create a Clinic object
        Clinic myClinic;

        // View default clinic hours
        cout << "Default clinic hours:\n";
        myClinic.viewClinicHours();

        // Update clinic hours
        cout << "\nUpdating clinic hours...\n";
        myClinic.setClinicHours(9, 18);

        // View updated clinic hours
        cout << "Updated clinic hours:\n";
        myClinic.viewClinicHours();

        // Attempt to set invalid clinic hours
        cout << "\nAttempting to set invalid clinic hours...\n";
        myClinic.setClinicHours(20, 6); // Invalid: Start hour is after the end hour
    }
    catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
