#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Patient {
public:
int id, age, bedNumber;
string name, ward;
bool admitted;

Patient(int i, string n, int a, string w, int b) {  
    id = i;  
    name = n;  
    age = a;  
    ward = w;  
    bedNumber = b;  
    admitted = true;  
}

};

class Hospital {
private:
vector<Patient> patients;
bool generalBeds[11]{};
bool icuBeds[6]{};
int nextId = 1001;

void saveData() {  
    ofstream file("hospital_data.txt");  

    if (!file) {  
        cout << "Error saving file!\n";  
        return;  
    }  

    file << nextId << '\n';  

    for (const auto& p : patients) {  
        file << p.id << '\n'  
             << p.age << '\n'  
             << p.bedNumber << '\n'  
             << p.ward << '\n'  
             << p.admitted << '\n'  
             << p.name << '\n';  
    }  
}  

void loadData() {  
    ifstream file("hospital_data.txt");  
    if (!file) return;  

    file >> nextId;  
    if (!file) return;  

    int id, age, bed;  
    bool active;  
    string ward, name;  

    while (file >> id >> age >> bed >> ward >> active) {  
        file.ignore(numeric_limits<streamsize>::max(), '\n');  
        getline(file, name);  

        if (ward != "General" && ward != "ICU")  
            continue;  

        if (bed < 1 ||  
            (ward == "General" && bed > 10) ||  
            (ward == "ICU" && bed > 5))  
            continue;  

        patients.emplace_back(id, name, age, ward, bed);  
        patients.back().admitted = active;  

        if (active) {  
            if (ward == "General")  
                generalBeds[bed] = true;  
            else  
                icuBeds[bed] = true;  
        }  
    }  
}  

int findBed(string ward) {  
    if (ward == "General") {  
        for (int i = 1; i <= 10; i++)  
            if (!generalBeds[i]) return i;  
    } else {  
        for (int i = 1; i <= 5; i++)  
            if (!icuBeds[i]) return i;  
    }  
    return -1;  
}

public:
Hospital() {
loadData();
}

void dashboard() {  
    int g = 0, i = 0;  

    for (int b = 1; b <= 10; b++)  
        if (generalBeds[b]) g++;  

    for (int b = 1; b <= 5; b++)  
        if (icuBeds[b]) i++;  

    cout << "\n========== HOSPITAL DASHBOARD ==========\n";  
    cout << "GENERAL WARD: Total 10 | Available "  
         << 10 - g << " | Occupied " << g << '\n';  
    cout << "ICU         : Total  5 | Available "  
         << 5 - i << " | Occupied " << i << '\n';  
    cout << "========================================\n";  
}  

void admitPatient() {  
    string name, ward;  
    int age, choice;  

    cout << "\n--- PATIENT REGISTRATION ---\n";  
    cout << "Patient name: ";  
    getline(cin >> ws, name);  

    cout << "Age: ";  
    if (!(cin >> age) || age < 0 || age > 125) {  
        cout << "Invalid age!\n";  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        return;  
    }  

    cout << "1. General Ward\n2. ICU\nChoice: ";  
    if (!(cin >> choice) || (choice != 1 && choice != 2)) {  
        cout << "Invalid choice!\n";  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        return;  
    }  

    ward = (choice == 1) ? "General" : "ICU";  
    int bed = findBed(ward);  

    if (bed == -1) {  
        cout << "No beds available in " << ward << "!\n";  
        return;  
    }  

    int id = nextId++;  
    patients.emplace_back(id, name, age, ward, bed);  

    if (ward == "General")  
        generalBeds[bed] = true;  
    else  
        icuBeds[bed] = true;  

    saveData();  

    cout << "\nAdmission successful!\n";  
    cout << "Patient ID: " << id << '\n';  
    cout << "Ward: " << ward << "\nBed: " << bed << '\n';  
}  

void showPatients() {  
    bool found = false;  

    cout << "\n--- ADMITTED PATIENTS ---\n";  

    for (const auto& p : patients) {  
        if (!p.admitted) continue;  

        found = true;  
        cout << "\nID: " << p.id  
             << "\nName: " << p.name  
             << "\nAge: " << p.age  
             << "\nWard: " << p.ward  
             << "\nBed: " << p.bedNumber << '\n';  
    }  

    if (!found) cout << "No admitted patients.\n";  
}  

void searchPatient() {  
    int id;  
    cout << "Enter patient ID: ";  

    if (!(cin >> id)) {  
        cout << "Invalid ID!\n";  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        return;  
    }  

    for (const auto& p : patients) {  
        if (p.id == id) {  
            cout << "\nName: " << p.name  
                 << "\nAge: " << p.age  
                 << "\nWard: " << p.ward  
                 << "\nBed: " << p.bedNumber  
                 << "\nStatus: "  
                 << (p.admitted ? "Admitted" : "Discharged")  
                 << '\n';  
            return;  
        }  
    }  

    cout << "Patient not found!\n";  
}  

void dischargePatient() {  
    int id;  
    cout << "Enter patient ID to discharge: ";  

    if (!(cin >> id)) {  
        cout << "Invalid ID!\n";  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        return;  
    }  

    for (auto& p : patients) {  
        if (p.id == id && p.admitted) {  
            p.admitted = false;  

            if (p.ward == "General")  
                generalBeds[p.bedNumber] = false;  
            else  
                icuBeds[p.bedNumber] = false;  

            saveData();  
            cout << "Discharge successful. Bed released!\n";  
            return;  
        }  
    }  

    cout << "Active patient not found!\n";  
}  

void occupancyReport() {  
    int g = 0, i = 0;  

    for (int b = 1; b <= 10; b++)  
        if (generalBeds[b]) g++;  

    for (int b = 1; b <= 5; b++)  
        if (icuBeds[b]) i++;  

    cout << "\n========== OCCUPANCY REPORT ==========\n";  
    cout << "General Ward: " << g << "/10 occupied ("  
         << g * 10 << "%)\n";  
    cout << "ICU: " << i << "/5 occupied ("  
         << i * 20 << "%)\n";  
    cout << "Overall: " << g + i << "/15 occupied ("  
         << (g + i) * 100 / 15 << "%)\n";  
}

};

int main() {
Hospital hospital;
int choice;

do {  
    cout << "\n====================================\n";  
    cout << " HOSPITAL & ICU BED MANAGEMENT\n";  
    cout << "====================================\n";  
    cout << "1. Dashboard\n";  
    cout << "2. Admit Patient\n";  
    cout << "3. Show Admitted Patients\n";  
    cout << "4. Search Patient\n";  
    cout << "5. Discharge Patient\n";  
    cout << "6. Occupancy Report\n";  
    cout << "0. Exit\n";  
    cout << "Enter choice: ";  

    if (!(cin >> choice)) {  
        cout << "Enter a valid number!\n";  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        continue;  
    }  

    switch (choice) {  
        case 1: hospital.dashboard(); break;  
        case 2: hospital.admitPatient(); break;  
        case 3: hospital.showPatients(); break;  
        case 4: hospital.searchPatient(); break;  
        case 5: hospital.dischargePatient(); break;  
        case 6: hospital.occupancyReport(); break;  
        case 0: cout << "Exiting system. Goodbye!\n"; break;  
        default: cout << "Invalid menu choice!\n";  
    }  
} while (choice != 0);  

return 0;

}