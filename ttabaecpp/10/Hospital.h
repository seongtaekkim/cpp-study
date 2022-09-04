#include "Doctor.h"
#include "Patient.h"
#include <iostream>
#include <vector>
#include <map>

class Hospital
{
private:
    std::vector<Patient*> patients;
    std::vector<Doctor*> doctors;
    std::map<std::string, std::string> meet;
public:
    Hospital() {}
    void addPatientByDoctor(Doctor * doctor, Patient * patient)
    {
        meet.insert(doctor->getName().c_str(), patient->getName().c_str());
    }
    void addDoctorByPatient(Patient * patient, Doctor * doctor)
    {
        meet.insert(patient->getName().c_str(), doctor->getName().c_str());
    }
    void addPatient(Patient * patient)
    {
        this->patients.push_back(patient);
    }
    void addDoctor(Doctor * doctor)
    {
        this->doctors.push_back(doctor);
    }
    void meetPatients()
    {
        for (auto &e : this->patients)
        {
            std::cout << "meet patients : " << e->getName() << std::endl;
        }
    }
    void meetDoctors()
    {
        for (auto &e : this->doctors)
        {
            std::cout << "meet doctor : " << e->getName() << std::endl;
        }
    }
};