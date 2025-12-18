#pragma once
#include "Person.h"
#include <string>
#include <memory>

class Doctor : public Person 
{
private:
    std::string specialization;
    std::string schedule;

public:
    Doctor(int id, const std::string& firstName, 
           const std::string& lastName, int age,
           const std::string& specialization, 
           const std::string& schedule);

    std::string getSpecialization() const;
    std::string getSchedule() const;
    std::string getInfo() const override;
};