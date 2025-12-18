#include "Patient.h"
#include <sstream>

Patient::Patient(int id, const std::string& firstName, 
                 const std::string& lastName, int age,
                 const std::string& medicalCardNumber)
    : Person(id, firstName, lastName, age), 
      medicalCardNumber(medicalCardNumber) {}

std::string Patient::getMedicalCardNumber() const 
{
    return medicalCardNumber;
}

std::string Patient::getInfo() const 
{
    std::ostringstream oss;
    oss << "Пациент: " << getFullName() 
        << ", Медкарта: " << medicalCardNumber
        << ", Возраст: " << getAge();
    return oss.str();
}