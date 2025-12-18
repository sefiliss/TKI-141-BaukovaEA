#include "Doctor.h"
#include <sstream>

Doctor::Doctor(int id, const std::string& firstName, 
               const std::string& lastName, int age,
               const std::string& specialization, 
               const std::string& schedule)
    : Person(id, firstName, lastName, age), 
      specialization(specialization), schedule(schedule) {}

std::string Doctor::getSpecialization() const 
{
    return specialization;
}

std::string Doctor::getSchedule() const 
{
    return schedule;
}

std::string Doctor::getInfo() const 
{
    std::ostringstream oss;
    oss << "Врач: " << getFullName() 
        << ", Специализация: " << specialization
        << ", Расписание: " << schedule
        << ", Возраст: " << getAge();
    return oss.str();
}