#pragma once
#include "Person.h"
#include <string>
#include <memory>

class Patient : public Person 
{
private:
    std::string medicalCardNumber;

public:
    Patient(int id, const std::string& firstName, 
            const std::string& lastName, int age,
            const std::string& medicalCardNumber);
    std::string getMedicalCardNumber() const;
    std::string getInfo() const override;
};