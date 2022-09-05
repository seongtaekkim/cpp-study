#include <iostream>
#include <vector>
#include <string>
#include "Patient.h"
#include "Doctor.h"
#include "Hospital.h"

int main(void)
{
    using namespace std;
    
    Patient *p1 = new Patient("kim1");
    Patient *p2 = new Patient("kim2");
    Patient *p3 = new Patient("kim3");

    Doctor *d1 = new Doctor("Doctor a");
    Doctor *d2 = new Doctor("Doctor b");

    Hospital *h = new Hospital();
    h->addDoctor(d1);
    h->addDoctor(d2);
    h->addPatient(p1);
    h->addPatient(p2);
    h->addPatient(p3);
   // h->addDoctorByPatient(p1, d1);
    h->addPatientByDoctor(d1, p1);
    h->addPatientByDoctor(d1, p2);
    h->addPatientByDoctor(d1, p3);
    
    // patients meet doctors
    //p1->addDoctor(d1);
    //d1->addPatient(p1);

    //p2->addDoctor(d2);
    //d2->addPatient(p2);

   // p2->addDoctor(d1);
    //d1->addPatient(p2);

   h->meetDoctors();
    //d1->meetPatients();
    // doctors meet patients

    //delete
    return (0);
}