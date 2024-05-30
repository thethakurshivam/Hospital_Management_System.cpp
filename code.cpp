#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Address {
public:
    string street, city, state, pin;
    Address() = default;
    Address(string& st, string& ci, string& sta, string& z)
    {
        this->street = st;
        this->city = ci;
        this->pin = z;
        this->state = sta;
    }
};

class Person {
public:
    string name;
    int age;
    Address address;

    Person() = default;
    Person( string& n, int a, Address& addr) 
    {
        this->name = n;
        this->address = addr;
        this->age = a;
    }

    virtual void addPerson() 
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter street: ";
        cin.ignore();
        getline(cin, address.street);
        cout << "Enter city: ";
        getline(cin, address.city);
        cout << "Enter state: ";
        getline(cin, address.state);
        cout << "Enter Pin Code : ";
        getline(cin, address.pin);
    }

    virtual void getDetails() 
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address.street << ", " << address.city << ", " << address.state << ", " << address.pin << "\n";
    }
};

class Patient : public Person {
public:
    Patient() = default;

    void hospitalize() 
    {
        cout << "Hospitalizing patient: " << name << "\n";
    }
};

class Doctor : public Person {
public:
    Doctor() = default;
};

class Nurse : public Person {
public:
    Nurse() = default;
};

class Driver : public Person {
public:
    Driver() = default;
};

class Appointment {
public:
    string patientName;
    string doctorName;
    string appointmentDate;

    Appointment() = default;

    void book() 
    {
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, patientName);
        cout << "Enter doctor name: ";
        getline(cin, doctorName);
        cout << "Enter appointment date (DD/MM/YYYY): ";
        getline(cin, appointmentDate);
    }

    void getDetails() 
    {
        cout << "Patient Name: " << patientName << "\n";
        cout << "Doctor Name: " << doctorName << "\n";
        cout << "Appointment Date: " << appointmentDate << "\n";
    }
};

class Hospital {
public:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Nurse> nurses;
    vector<Driver> drivers;
    vector<Appointment> appointments;

    void printPatients() 
    {
        for (auto& patient : patients) 
        {
            patient.getDetails();
            cout<<endl;
        }
    }

    void printDoctors() 
    {
        for (auto& doctor : doctors) 
        {
            doctor.getDetails();
            cout<<endl;
        }
    }

    void printNurses() 
    {
        for (auto& nurse : nurses) 
        {
            nurse.getDetails();
            cout<<endl;
        }
    }

    void printDrivers() 
    {
        for (auto& driver : drivers) 
        {
            driver.getDetails();
            cout<<endl;
        }
    }

    void printAppointments() 
    {
        for (auto& appointment : appointments) 
        {
            appointment.getDetails();
            cout<<endl;
        }
    }
};

void appointmentsMenu(Hospital& hospital);
void patientsMenu(Hospital& hospital);
void doctorsMenu(Hospital& hospital);
void nursesMenu(Hospital& hospital);
void driversMenu(Hospital& hospital);

void appointmentsMenu(Hospital& hospital) 
{
    bool exit = false;
    while (!exit) {
        int choice = 0;
        cout << "\nAPPOINTMENTS MENU\n";
        cout << "1. Book an appointment\n";
        cout << "2. Get appointment details\n";
        cout << "3. Show all appointments\n";
        cout << "-1. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Appointment a;
            a.book();
            hospital.appointments.push_back(a);
        } else if (choice == 2) {
            for (auto& a : hospital.appointments) {
                a.getDetails();
                break;
            }
        } else if (choice == 3) {
            hospital.printAppointments();
        } else if (choice == -1) {
            exit = true;
        } else {
            cout << "Invalid choice!\n";
        }

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
}

void patientsMenu(Hospital& hospital) 
{
    bool exit = false;
    while (!exit) {
        int choice = 0;
        cout << "\nPATIENTS MENU\n";
        cout << "1. Register a new patient\n";
        cout << "2. Get most recent patient details\n";
        cout << "3. Hospitalize a patient\n";
        cout << "4. Show all patients\n";
        cout << "-1. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.addPerson();
            hospital.patients.push_back(p);
        } else if (choice == 2) {
            if (!hospital.patients.empty()) {
                hospital.patients.back().getDetails();
            } else {
                cout << "No patients registered.\n";
            }
        } else if (choice == 3) {
            for (auto& p : hospital.patients) {
                p.hospitalize();
                break;
            }
        } else if (choice == 4) {
            hospital.printPatients();
        } else if (choice == -1) {
            exit = true;
        } else {
            cout << "Invalid choice!\n";
        }

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
}

void doctorsMenu(Hospital& hospital) 
{
    bool exit = false;
    while (!exit) {
        int choice = 0;
        cout << "\nDOCTORS MENU\n";
        cout << "1. Register a new doctor\n";
        cout << "2. Get doctor details\n";
        cout << "3. Show all doctors\n";
        cout << "-1. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Doctor d;
            d.addPerson();
            hospital.doctors.push_back(d);
        } else if (choice == 2) {
            for (auto& d : hospital.doctors) {
                d.getDetails();
                break;
            }
        } else if (choice == 3) {
            hospital.printDoctors();
        } else if (choice == -1) {
            exit = true;
        } else {
            cout << "Invalid choice!\n";
        }

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
}

void nursesMenu(Hospital& hospital) 
{
    bool exit = false;
    while (!exit) {
        int choice = 0;
        cout << "\nNURSES MENU\n";
        cout << "1. Register a new nurse\n";
        cout << "2. Get nurse details\n";
        cout << "3. Show all nurses\n";
        cout << "-1. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Nurse n;
            n.addPerson();
            hospital.nurses.push_back(n);
        } else if (choice == 2) {
            for (auto& n : hospital.nurses) {
                n.getDetails();
                break;
            }
        } else if (choice == 3) {
            hospital.printNurses();
        } else if (choice == -1) {
            exit = true;
        } else {
            cout << "Invalid choice!\n";
        }

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
}

void driversMenu(Hospital& hospital) 
{
    bool exit = false;
    while (!exit) {
        int choice = 0;
        cout << "\nDRIVERS MENU\n";
        cout << "1. Register a new driver\n";
        cout << "2. Get driver details\n";
        cout << "3. Show all drivers\n";
        cout << "-1. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Driver d;
            d.addPerson();
            hospital.drivers.push_back(d);
        } else if (choice == 2) {
            for (auto& d : hospital.drivers) {
                d.getDetails();
            }
        } else if (choice == 3) {
            hospital.printDrivers();
        } else if (choice == -1) {
            exit = true;
        } else {
            cout << "Invalid choice!\n";
        }

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
}

void displayMenu() {
    cout << "\n-----------------------------\n";
    cout << "Select a category:\n\n";
    cout << "[01] : APPOINTMENTS\n";
    cout << "[02] : PATIENTS\n";
    cout << "[03] : DOCTORS\n";
    cout << "[04] : NURSES\n";
    cout << "[05] : DRIVERS\n";
    cout << "[-1] : EXIT\n";
    cout << "-----------------------------\n\n";
    cout << "Enter your choice: ";
}

void handleChoice(int choice, Hospital& hospital) 
{
    switch (choice) {
        case 1:
            appointmentsMenu(hospital);
            break;
        case 2:
            patientsMenu(hospital);
            break;
        case 3:
            doctorsMenu(hospital);
            break;
        case 4:
            nursesMenu(hospital);
            break;
        case 5:
            driversMenu(hospital);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

int main() {
    Hospital hospital;
    int choice = 0;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == -1) {
            cout << "Exiting the system...\n";
            break;
        }

        handleChoice(choice, hospital);

        cin.ignore();
        cout << "\nPress ENTER to continue...\n";
        cin.get();
    }
    return 0;
}
