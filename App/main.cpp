#include <iostream>
#include <memory>
#include <vector>
#include "Polyclinic.h"
#include "Person.h"

int main() 
{
    try 
    {
        Polyclinic polyclinic;
        auto doctor1 = polyclinic.createDoctor("Иван", "Петров", 45, 
                                              "Терапевт", "Пн-Пт 9:00-17:00");
        auto doctor2 = polyclinic.createDoctor("Анна", "Сидорова", 38, 
                                              "Хирург", "Вт-Сб 10:00-18:00");
        auto doctor3 = polyclinic.createDoctor("Михаил", "Смирнов", 52, 
                                              "Кардиолог", "Пн-Ср-Пт 8:00-16:00");
        
        polyclinic.addDoctor(doctor1);
        polyclinic.addDoctor(doctor2);
        polyclinic.addDoctor(doctor3);

        auto patient1 = polyclinic.createPatient("Сергей", "Иванов", 30, "MC12345");
        auto patient2 = polyclinic.createPatient("Мария", "Кузнецова", 25, "MC67890");
        auto patient3 = polyclinic.createPatient("Алексей", "Попов", 42, "MC54321");
        
        polyclinic.addPatient(patient1);
        polyclinic.addPatient(patient2);
        polyclinic.addPatient(patient3);

        auto appointment1 = polyclinic.createAppointment(doctor1, patient1, 
                                                        "2024-10-10", "10:00");
        auto appointment2 = polyclinic.createAppointment(doctor2, patient2, 
                                                        "2024-10-11", "11:00");
        auto appointment3 = polyclinic.createAppointment(doctor3, patient3, 
                                                        "2024-10-12", "14:30");
        
        polyclinic.addAppointment(appointment1);
        polyclinic.addAppointment(appointment2);
        polyclinic.addAppointment(appointment3);

        std::cout << "Сводная информация обо всех врачах поликлиники" << std::endl;
        auto doctorsSummary = polyclinic.getAllDoctorsSummary();
        for (const auto& summary : doctorsSummary) 
        {
            std::cout << summary << std::endl;
        }

        std::cout << "\n ЗАДАНИЕ 2: Сводная информация о пациентах" << std::endl;
        auto patientsSummary = polyclinic.getAllPatientsSummary();
        for (const auto& summary : patientsSummary) 
        {
            std::cout << summary << std::endl;
        }

        std::cout << "\nЗАДАНИЕ 3: Информация о записи пациента к врачу" << std::endl;
        auto appointmentsInfo = polyclinic.getAllAppointmentsInfo();
        for (const auto& info : appointmentsInfo) 
        {
            std::cout << info << std::endl;
        }

        std::cout << "Коллекция объектов базового типа Person:" << std::endl;
        std::vector<std::shared_ptr<Person>> people = polyclinic.getAllPeople();
        for (const auto& person : people) 
        {
            std::cout << person->getInfo() << std::endl;
        }

    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}