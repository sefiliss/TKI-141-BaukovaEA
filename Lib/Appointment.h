#pragma once
#include <string>
#include <memory>
#include "Doctor.h"
#include "Patient.h"

class Appointment 
{
private:
    std::shared_ptr<Doctor> doctor;
    std::shared_ptr<Patient> patient;
    std::string date;
    std::string time;
public:
    Appointment(const std::shared_ptr<Doctor>& doctor, 
                const std::shared_ptr<Patient>& patient,
                const std::string& date, const std::string& time);

    std::shared_ptr<const Doctor> getDoctor() const;
    std::shared_ptr<const Patient> getPatient() const;
    std::string getDate() const;
    std::string getTime() const;
    std::string getInfo() const;
};