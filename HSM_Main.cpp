#include <iostream>
using namespace std;

// ********************
// 1. LARGE CLASS
// Does too many things: patient, doctor, billing, appointments
// ********************
class HospitalSystem {
public:
    // arrays for patients
    string patientName[10];
    int patientAge[10];
    string patientDisease[10];

    // doctor info
    string doctorName[10];
    string doctorSpec[10];

    // billing info
    int billAmount[10];

    int patientCount = 0;
    int doctorCount = 0;

    // ------------------------------
    // 2. DUPLICATE CODE (same code repeated)
    // ------------------------------
    void addPatient(string name, int age, string disease) {
        patientName[patientCount] = name;
        patientAge[patientCount] = age;
        patientDisease[patientCount] = disease;
        patientCount++;

        cout << "Patient Added!\n";
    }

    void addDoctor(string name, string spec) {
        doctorName[doctorCount] = name;
        doctorSpec[doctorCount] = spec;
        doctorCount++;

        cout << "Doctor Added!\n";
    }

    // ------------------------------
    // 3. LONG PARAMETER LIST
    // ------------------------------
    void createBill(string patientName, int days, int roomCharges, int medicine, int tests,
                    int surgery, int extra1, int extra2) {
        int total = days + roomCharges + medicine + tests + surgery + extra1 + extra2;
        cout << "Bill for " << patientName << " = " << total << endl;
    }

    // ------------------------------
    // 4. FEATURE ENVY
    // This function uses doctor data too much instead of Doctor class
    // ------------------------------
    void showDoctorDetails(int index) {
        cout << "Doctor Name: " << doctorName[index] << endl;
        cout << "Specialization: " << doctorSpec[index] << endl;
    }

    // ------------------------------
    // 5. SHOTGUN SURGERY
    // To add a new field (e.g., doctorPhone), we must change 5+ places
    // ------------------------------
    void printAllDoctors() {
        for (int i = 0; i < doctorCount; i++) {
            cout << doctorName[i] << " - " << doctorSpec[i] << endl;
        }
    }

    // ------------------------------
    // 6. DIVERGENT CHANGE
    // This one class handles patient, doctor, billing -> many change reasons
    // ------------------------------
    void updatePatientDisease(int index, string newDisease) {
        patientDisease[index] = newDisease;
    }

    // ------------------------------
    // 7. PRIMITIVE OBSESSION
    // Using string instead of separate classes like Name, Disease, etc.
    // ------------------------------

    // ------------------------------
    // 8. SWITCH STATEMENTS
    // Many if/switch instead of polymorphism
    // ------------------------------
    void getDoctorType(int index) {
        string spec = doctorSpec[index];

        if (spec == "Heart") cout << "Cardiologist\n";
        else if (spec == "Bones") cout << "Orthopedic\n";
        else if (spec == "Eyes") cout << "Ophthalmologist\n";
        else cout << "General Doctor\n";
    }

    // ------------------------------
    // 9. LAZY CLASS
    // A class that does almost nothing
    // ------------------------------
    class Helper {
    public:
        void printMsg() { cout << "Helper\n"; }
    };

    // ------------------------------
    // 10. DATA CLUMPS
    // Same 3 items passed together everywhere: name, age, disease
    // ------------------------------
    void showPatient(string name, int age, string disease) {
        cout << name << " - " << age << " - " << disease << endl;
    }
};


// --------------------------------
// MAIN (RUNNABLE)
// --------------------------------
int main() {
    HospitalSystem hs;

    // Using bad smell code
    hs.addPatient("Ali", 30, "Flu");
    hs.addPatient("Sara", 40, "Fever");

    hs.addDoctor("Dr. Ahmed", "Heart");
    hs.addDoctor("Dr. Bilal", "Eyes");

    hs.createBill("Ali", 2, 500, 300, 200, 0, 20, 10);

    hs.showDoctorDetails(0);
    hs.getDoctorType(1);

    hs.showPatient("Ali", 30, "Flu");

    return 0;
}
