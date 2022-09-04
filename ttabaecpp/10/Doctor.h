#include <string>

#ifndef DOCTOR_H
 #define DOCTOR_H

class Doctor
{
private:
    std::string name;
public:
    Doctor();
    Doctor(const std::string name);
    std::string getName();
};

#endif