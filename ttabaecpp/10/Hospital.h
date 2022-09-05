#include "Doctor.h"
#include "Patient.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Hospital
{
private:
    std::vector<Patient*> patients;
    std::vector<Doctor*> doctors;
    std::map<std::string, std::vector<std::string>> meet;
public:
    Hospital() {}
    void addPatientByDoctor(Doctor * doctor, Patient * patient)
    {
        string ret ;
        vector<string> ret2;
        for (auto iter = meet.begin(); iter != meet.end(); ++iter) {
           ret= iter->first;
           iter->second.push_back(patient->getName());
        }
        
        if (ret.compare(doctor->getName()) != 0)
        {
            vector<string> in;
            in.push_back(patient->getName());
            meet.insert(make_pair(doctor->getName(), in));
        }
    }
/*     void addDoctorByPatient(Patient * patient, Doctor * doctor)
    {
        meet.insert(patient->getName().c_str(), doctor->getName().c_str());
    } */
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
        string ret;
        vector<string> ret2;

        for (auto iter = meet.begin(); iter != meet.end(); ++iter) {
           ret= iter->first;
           ret2 = iter->second;
        }

        for (auto &e : ret2)
        {
            cout << e << " ";
        }
        cout << endl;

    }
};