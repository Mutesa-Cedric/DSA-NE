#include <iostream>

using namespace std;


// patient, doctor and appointment structures
struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
};

struct Doctor {
    int doctor_id;
    string name;
    string specialization;
};

struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
};


// Node to store LinkedList item
// It's generic so that it can be used for any LinkedList type
template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T val) : data(val), next(nullptr) {}
};

// Linked list to store patients
class PatientsLL {
private:
    Node<Patient> *head;

public:
    PatientsLL() : head(nullptr) {}

    //find patient by id
    bool findById(int patient_id) {
        bool isFound = false;
        Node<Patient> *current = head;
        while (current != nullptr) {
            //patient id already exists
            if (current->data.patient_id == patient_id) {
                return true;
            }
        }
        return isFound;
    }

    // saving a patient
    void addPatient(Patient patient) {
        if (findById(patient.patient_id) == 0) {
            // create a new node containing the patient
            Node<Patient> *newPatient = new Node<Patient>(patient);

            // check if PatientsLL is empty and make the newPatient the head
            if (head == nullptr) {
                head = newPatient;
            } else {
                Node<Patient> *current = head;
                //3. move the patient to the end of the linked list
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newPatient;
            }
        } else {
            cout << "Patient with that id already exists" << endl;
        }

    }

    // print patients in PatientsLL to terminal
    void displayPatients() {
        Node<Patient> *current = head;

        //loop over the elements in the linked list
        while (current != nullptr) {
            cout << "Patient ID: " << current->data.patient_id << ", " << "Name: " << current->data.name << ", "
                 << "DOB: " << current->data.dob << ", " << "Gender: " << current->data.gender << endl;
            current = current->next;
        }
    }

    // Destructor to free allocated memory
    ~PatientsLL() {
        while (head != nullptr) {
            Node<Patient> *temp = head;
            head = head->next;
            delete temp;
        }
    }

};

//Linked list to store doctors
class DoctorsLL {
private:
    Node<Doctor> *head;
public:
    DoctorsLL() : head(nullptr) {}

    //find doctor by id
    bool findById(int doctor_id) {
        bool isFound = false;
        Node<Doctor> *current = head;
        while (current != nullptr) {
            //patient id already exists
            if (current->data.doctor_id == doctor_id) {
                return true;
            }
        }
        return isFound;
    }

    // saving a doctor in linked list
    void addDoctor(Doctor doctor) {
        if (findById(doctor.doctor_id) == 1) {
            cout << "Doctor with that id already exists" << endl;
            return;
        }
        //create a new node containing the patient
        Node<Doctor> *newDoctor = new Node<Doctor>(doctor);

        //check if DoctorsLL is empty and make the newDoctor the head
        if (head == nullptr) {
            head = newDoctor;
        } else {
            Node<Doctor> *current = head;
            //move the patient to the end of the linked list
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newDoctor;
        }
    }

    // print doctors in DoctorsLL to terminal
    void displayDoctors() {
        Node<Doctor> *current = head;

        //loop over the elements in the linked list
        while (current != nullptr) {
            cout << "Doctor ID: " << current->data.doctor_id << ", " << "Name: " << current->data.name << ", "
                 << " Specialization: " << current->data.specialization << endl;
            current = current->next;
        }
    }

    // Destructor to free allocated memory
    ~DoctorsLL() {
        while (head != nullptr) {
            Node<Doctor> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//Linked list to store appointments
class AppointmentsLL {
private:
    Node<Appointment> *head;
public:
    AppointmentsLL() : head(nullptr) {}

    //find appointment by id
    bool findById(int appointment_id) {
        bool isFound = false;
        Node<Appointment> *current = head;
        while (current != nullptr) {
            //patient id already exists
            if (current->data.appointment_id == appointment_id) {
                return true;
            }
        }
        return isFound;
    }

    // saving an appointment in linked list
    void addAppointment(Appointment appointment) {

        if (findById(appointment.appointment_id) == 1) {
            cout << "appointment with that id already exists" << endl;
            return;
        }

        //create a new node containing the patient
        Node<Appointment> *newAppointment = new Node<Appointment>(appointment);

        //check if AppointmentsLL is empty and make the newAppointment the head
        if (head == nullptr) {
            head = newAppointment;
        } else {
            Node<Appointment> *current = head;
            //move appointment to the end of the linked list
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newAppointment;
        }
    }

    // print appointments in AppointmentsLL to terminal
    void displayAppointments() {
        Node<Appointment> *current = head;

        //loop over the elements in the linked list
        while (current != nullptr) {
            cout << "Appointment ID: " << current->data.appointment_id << ", " << "Patient ID: "
                 << current->data.patient_id << ", "
                 << " Doctor ID: " << current->data.doctor_id << " Date: " << current->data.appointment_date << endl;
            current = current->next;
        }
    }

    // Destructor to free allocated memory
    ~AppointmentsLL() {
        while (head != nullptr) {
            Node<Appointment> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    //variables
    int choice;
    PatientsLL patientsList;
    DoctorsLL doctorsList;
    AppointmentsLL appointmentsList;

    // loop which will keep the program running forever unless exit is selected
    while (true) {

        // menu
        cout << "Menu:" << endl;
        cout << "1. Register a Patient" << endl;
        cout << "2. Register a Doctor" << endl;
        cout << "3. Register an appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;

        // receive user choice
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int patient_id;
            string patient_name, dob, gender;

            //receive patients data
            cout << "PATIENT REGISTRATION" << endl;
            cout << "------------------------" << endl;
            cout << "ID: ";
            cin >> patient_id;
            cin.ignore();
            cout << "NAME: ";
            getline(cin, patient_name);
            cout << "DoB: ";
            getline(cin, dob);
            cout << "GENDER: ";
            getline(cin, gender);

            // create a patient object with the given data
            Patient patient = {patient_id, patient_name, dob, gender};

            //add to patients list
            patientsList.addPatient(patient);
        } else if (choice == 2) {
            int doctor_id;
            string name, specialization;

            // receive doctor's data
            cout << "DOCTOR REGISTRATION" << endl;
            cout << "---------------------------" << endl;

            cout << "ID: ";
            cin >> doctor_id;
            cin.ignore();
            cout << "NAME: ";
            getline(cin, name);
            cout << "SPECIALIZATION: ";
            getline(cin, specialization);

            Doctor doctor = {doctor_id, name, specialization};
            doctorsList.addDoctor(doctor);

        } else if (choice == 3) {
            int appointment_id, patient_id, doctor_id;
            string appointment_date;

            cout << "APPOINTMENT REGISTRATION" << endl;
            cout << "------------------------" << endl;

            cout << "ID: ";
            cin >> appointment_id;
            cin.ignore();
            cout << "P_ID: ";
            cin >> patient_id;
            cin.ignore();
            cout << "D_ID";
            cin >> doctor_id;
            cin.ignore();
            cout << "DATE: ";
            getline(cin, appointment_date);

            Appointment appointment = {appointment_id, patient_id, doctor_id, appointment_date};
            appointmentsList.addAppointment(appointment);
        } else if (choice == 4) {
            patientsList.displayPatients();
        } else if (choice == 5) {
            doctorsList.displayDoctors();
        } else if (choice == 6) {
            appointmentsList.displayAppointments();
        } else if (choice == 7) {
            cout << "Exiting the system ..." << endl;
            exit(0);
        } else {
            cout << "Invalid option" << endl;
        }
    }
}
