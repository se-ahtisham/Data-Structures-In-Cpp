#include <iostream>
using namespace std;

class HospitalSystem {
public:
    string patientName[10];
    int patientAge[10];
    string patientDisease[10];

    string doctorName[10];
    string doctorSpec[10];

    int billAmount[10];

    int patientCount = 0;
    int doctorCount = 0;

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

    void createBill(string patientName, int days, int roomCharges, int medicine, int tests,
                    int surgery, int extra1, int extra2) {
        int total = days + roomCharges + medicine + tests + surgery + extra1 + extra2;
        cout << "Bill for " << patientName << " = " << total << endl;
    }

    void showDoctorDetails(int index) {
        cout << "Doctor Name: " << doctorName[index] << endl;
        cout << "Specialization: " << doctorSpec[index] << endl;
    }

    void printAllDoctors() {
        for (int i = 0; i < doctorCount; i++) {
            cout << doctorName[i] << " - " << doctorSpec[i] << endl;
        }
    }

    void updatePatientDisease(int index, string newDisease) {
        patientDisease[index] = newDisease;
    }

    void getDoctorType(int index) {
        string spec = doctorSpec[index];
        if (spec == "Heart") cout << "Cardiologist\n";
        else if (spec == "Bones") cout << "Orthopedic\n";
        else if (spec == "Eyes") cout << "Ophthalmologist\n";
        else cout << "General Doctor\n";
    }

    class Helper {
    public:
        void printMsg() { cout << "Helper\n"; }
    };

    void showPatient(string name, int age, string disease) {
        cout << name << " - " << age << " - " << disease << endl;
    }
};

int main() {
    HospitalSystem hs;

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
