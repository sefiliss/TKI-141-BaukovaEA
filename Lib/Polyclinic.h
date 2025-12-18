#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

class Polyclinic 
{
private:
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::vector<std::shared_ptr<Patient>> patients;
    std::vector<std::shared_ptr<Appointment>> appointments;
    int nextId;

public:
    Polyclinic();
    std::shared_ptr<Doctor> createDoctor(const std::string& firstName, 
                                        const std::string& lastName, 
                                        int age,
                                        const std::string& specialization, 
                                        const std::string& schedule);
    
    std::shared_ptr<Patient> createPatient(const std::string& firstName, 
                                          const std::string& lastName, 
                                          int age,
                                          const std::string& medicalCardNumber);
    
    std::shared_ptr<Appointment> createAppointment(
        const std::shared_ptr<Doctor>& doctor,
        const std::shared_ptr<Patient>& patient,
        const std::string& date, const std::string& time);
    void addDoctor(const std::shared_ptr<Doctor>& doctor);
    void addPatient(const std::shared_ptr<Patient>& patient);
    void addAppointment(const std::shared_ptr<Appointment>& appointment);
    std::vector<std::string> getAllDoctorsSummary() const;
    std::vector<std::string> getAllPatientsSummary() const;
    std::vector<std::string> getAllAppointmentsInfo() const;
    std::vector<std::shared_ptr<Person>> getAllPeople() const;
    std::vector<std::shared_ptr<const Doctor>> getDoctors() const;
    std::vector<std::shared_ptr<const Patient>> getPatients() const;
    std::vector<std::shared_ptr<const Appointment>> getAppointments() const;
};