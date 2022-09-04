#include "Doctor.h"
#include <string>
#include "Hospital.h"

Doctor::Doctor() {}
Doctor::Doctor(const std::string name)
    : name(name) {}
std::string Doctor::getName()
{
    return (name);
}