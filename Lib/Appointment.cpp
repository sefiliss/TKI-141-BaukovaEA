#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include <sstream>
#include <stdexcept>

Appointment::Appointment(const std::shared_ptr<Doctor>& doctor, 
                         const std::shared_ptr<Patient>& patient,
                         const std::string& date, const std::string& time)
    : doctor(doctor), patient(patient), date(date), time(time) 
{
    
    if (!doctor || !patient) 
    {
        throw std::invalid_argument("Данные о докторе и пациенте отсутствуют");
    }
}

std::shared_ptr<const Doctor> Appointment::getDoctor() const 
{
    return doctor;
}

std::shared_ptr<const Patient> Appointment::getPatient() const 
{
    return patient;
}

std::string Appointment::getDate() const 
{
    return date;
}

std::string Appointment::getTime() const 
{
    return time;
}

std::string Appointment::getInfo() const 
{
    std::ostringstream oss;
    oss << "Запись на " << date << " " << time << "\n"
        << "Врач: " << doctor->getInfo() << "\n"
        << "Пациент: " << patient->getInfo();
    return oss.str();
}
