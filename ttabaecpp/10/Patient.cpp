#include <string>
#include "Patient.h"

Patient::Patient() {}
Patient::Patient(const std::string name)
    : name(name) {}
std::string Patient::getName()
{
    return (name);
}
