#include "Polyclinic.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include <stdexcept>

Polyclinic::Polyclinic() : nextId(1) {}

std::shared_ptr<Doctor> Polyclinic::createDoctor(
    const std::string& firstName, const std::string& lastName, int age,
    const std::string& specialization, const std::string& schedule) 
{
    
    return std::make_shared<Doctor>(nextId++, firstName, lastName, age, 
                                    specialization, schedule);
}

std::shared_ptr<Patient> Polyclinic::createPatient(
    const std::string& firstName, const std::string& lastName, int age,
    const std::string& medicalCardNumber) 
{
    
    return std::make_shared<Patient>(nextId++, firstName, lastName, age, 
                                     medicalCardNumber);
}

std::shared_ptr<Appointment> Polyclinic::createAppointment(
    const std::shared_ptr<Doctor>& doctor,
    const std::shared_ptr<Patient>& patient,
    const std::string& date, const std::string& time) 
    
{
    
    if (!doctor || !patient) 
    {
        throw std::invalid_argument("Данные о докторе и пациенте отсутствуют");
    }
    
    return std::make_shared<Appointment>(doctor, patient, date, time);
}

void Polyclinic::addDoctor(const std::shared_ptr<Doctor>& doctor) 
{
    if (!doctor) 
    {
        throw std::invalid_argument("Данные о докторе отсутствуют");
    }
    doctors.push_back(doctor);
}

void Polyclinic::addPatient(const std::shared_ptr<Patient>& patient) 
{
    if (!patient) 
    {
        throw std::invalid_argument("Данные о пациенте отсутствуют");
    }
    patients.push_back(patient);
}

void Polyclinic::addAppointment(const std::shared_ptr<Appointment>& appointment) 
{
    if (!appointment) 
    {
        throw std::invalid_argument("Данные о расписании отсутствуют");
    }
    appointments.push_back(appointment);
}

// 1. Сводная информация о врачах
std::vector<std::string> Polyclinic::getAllDoctorsSummary() const 
{
    std::vector<std::string> result;
    for (const auto& doctor : doctors) 
    {
        result.push_back(doctor->getInfo());
    }
    return result;
}

// 2. Сводная информация о пациентах
std::vector<std::string> Polyclinic::getAllPatientsSummary() const 
{
    std::vector<std::string> result;
    for (const auto& patient : patients) {
        result.push_back(patient->getInfo());
    }
    return result;
}

// 3. Информация о записях
std::vector<std::string> Polyclinic::getAllAppointmentsInfo() const 
{
    std::vector<std::string> result;
    for (const auto& appointment : appointments) 
    {
        result.push_back(appointment->getInfo());
    }
    return result;
}

std::vector<std::shared_ptr<Person>> Polyclinic::getAllPeople() const 
{
    std::vector<std::shared_ptr<Person>> result;
    
    for (const auto& doctor : doctors) 
    {
        result.push_back(doctor);
    }

    for (const auto& patient : patients) 
    {
        result.push_back(patient);
    }
    
    return result;
}

std::vector<std::shared_ptr<const Doctor>> Polyclinic::getDoctors() const 
{
    std::vector<std::shared_ptr<const Doctor>> result;
    result.reserve(doctors.size());
    for (const auto& doctor : doctors) {
        result.push_back(doctor);
    }
    return result;
}

std::vector<std::shared_ptr<const Patient>> Polyclinic::getPatients() const 
{
    std::vector<std::shared_ptr<const Patient>> result;
    result.reserve(patients.size());
    for (const auto& patient : patients) {
        result.push_back(patient);
    }
    return result;
}

std::vector<std::shared_ptr<const Appointment>> Polyclinic::getAppointments() const 
{
    std::vector<std::shared_ptr<const Appointment>> result;
    result.reserve(appointments.size());
    for (const auto& appointment : appointments) {
        result.push_back(appointment);
    }
    return result;
}