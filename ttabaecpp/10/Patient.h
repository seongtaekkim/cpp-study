#include <string>
#ifndef PATIENT_H
 #define PATIENT_H

class Patient
{
private:
    std::string name;
public:
    Patient();
    Patient(const std::string name);
    std::string getName();

};

#endif