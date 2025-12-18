#include <gtest/gtest.h>
#include <sstream>
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "Polyclinic.h"

TEST(PersonTest, ConstructorAndGetters) 
{
    Person* person = new Doctor(1, "Иван", "Петров", 45, "Терапевт", "9-17");
    
    EXPECT_EQ(person->getId(), 1);
    EXPECT_EQ(person->getFirstName(), "Иван");
    EXPECT_EQ(person->getLastName(), "Петров");
    EXPECT_EQ(person->getAge(), 45);
    EXPECT_EQ(person->getFullName(), "Иван Петров");
    
    delete person;
}

TEST(PersonTest, GetFullName) 
{
    Person* person = new Patient(2, "Анна", "Сидорова", 30, "MC123");
    
    EXPECT_EQ(person->getFullName(), "Анна Сидорова");
    
    delete person;
}

TEST(DoctorTest, ConstructorAndGetters) 
{
    Doctor doctor(1, "Иван", "Петров", 45, "Терапевт", "Пн-Пт 9:00-17:00");
    
    EXPECT_EQ(doctor.getId(), 1);
    EXPECT_EQ(doctor.getFirstName(), "Иван");
    EXPECT_EQ(doctor.getLastName(), "Петров");
    EXPECT_EQ(doctor.getAge(), 45);
    EXPECT_EQ(doctor.getSpecialization(), "Терапевт");
    EXPECT_EQ(doctor.getSchedule(), "Пн-Пт 9:00-17:00");
}

TEST(DoctorTest, GetInfo) 
{
    Doctor doctor(1, "Иван", "Петров", 45, "Терапевт", "Пн-Пт 9:00-17:00");
    
    std::string info = doctor.getInfo();
    EXPECT_NE(info.find("Врач"), std::string::npos);
    EXPECT_NE(info.find("Иван Петров"), std::string::npos);
    EXPECT_NE(info.find("Терапевт"), std::string::npos);
    EXPECT_NE(info.find("Пн-Пт 9:00-17:00"), std::string::npos);
}

TEST(PatientTest, ConstructorAndGetters) 
{
    Patient patient(1, "Сергей", "Иванов", 30, "MC12345");
    
    EXPECT_EQ(patient.getId(), 1);
    EXPECT_EQ(patient.getFirstName(), "Сергей");
    EXPECT_EQ(patient.getLastName(), "Иванов");
    EXPECT_EQ(patient.getAge(), 30);
    EXPECT_EQ(patient.getMedicalCardNumber(), "MC12345");
}

TEST(PatientTest, GetInfo) 
{
    Patient patient(1, "Сергей", "Иванов", 30, "MC12345");
    
    std::string info = patient.getInfo();
    EXPECT_NE(info.find("Пациент"), std::string::npos);
    EXPECT_NE(info.find("Сергей Иванов"), std::string::npos);
    EXPECT_NE(info.find("MC12345"), std::string::npos);
}

TEST(AppointmentTest, ConstructorAndGetters) 
{
    auto doctor = std::make_shared<Doctor>(1, "Иван", "Петров", 45, "Терапевт", "9-17");
    auto patient = std::make_shared<Patient>(2, "Сергей", "Иванов", 30, "MC123");
    
    Appointment appointment(doctor, patient, "2024-10-10", "10:00");
    
    EXPECT_EQ(appointment.getDoctor()->getId(), 1);
    EXPECT_EQ(appointment.getPatient()->getId(), 2);
    EXPECT_EQ(appointment.getDate(), "2024-10-10");
    EXPECT_EQ(appointment.getTime(), "10:00");
}

TEST(AppointmentTest, GetInfo) 
{
    auto doctor = std::make_shared<Doctor>(1, "Иван", "Петров", 45, "Терапевт", "9-17");
    auto patient = std::make_shared<Patient>(2, "Сергей", "Иванов", 30, "MC123");
    
    Appointment appointment(doctor, patient, "2024-10-10", "10:00");
    
    std::string info = appointment.getInfo();
    EXPECT_NE(info.find("Запись на"), std::string::npos);
    EXPECT_NE(info.find("2024-10-10"), std::string::npos);
    EXPECT_NE(info.find("10:00"), std::string::npos);
}

TEST(AppointmentTest, InvalidConstructor)
{
    auto doctor = std::make_shared<Doctor>(1, "Иван", "Петров", 45, "Терапевт", "9-17");
    
    EXPECT_THROW(Appointment(doctor, nullptr, "2024-10-10", "10:00"), std::invalid_argument);
    EXPECT_THROW(Appointment(nullptr, nullptr, "2024-10-10", "10:00"), std::invalid_argument);
}

TEST(PolyclinicTest, DefaultConstructor) {
    Polyclinic polyclinic;
    
    EXPECT_EQ(polyclinic.getAllPeople().size(), 0);
}

TEST(PolyclinicTest, CreateAndAddDoctor) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    polyclinic.addDoctor(doctor);
    
    EXPECT_EQ(polyclinic.getAllPeople().size(), 1);
    
    auto doctors = polyclinic.getDoctors();
    EXPECT_EQ(doctors.size(), 1);
    EXPECT_EQ(doctors[0]->getFullName(), "Иван Петров");
}

TEST(PolyclinicTest, CreateAndAddPatient) 
{
    Polyclinic polyclinic;
    
    auto patient = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    polyclinic.addPatient(patient);
    
    EXPECT_EQ(polyclinic.getAllPeople().size(), 1);
    
    auto patients = polyclinic.getPatients();
    EXPECT_EQ(patients.size(), 1);
    EXPECT_EQ(patients[0]->getFullName(), "Сергей Иванов");
}

TEST(PolyclinicTest, CreateAndAddAppointment) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto patient = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    
    polyclinic.addDoctor(doctor);
    polyclinic.addPatient(patient);
    
    auto appointment = polyclinic.createAppointment(doctor, patient, "2024-10-10", "10:00");
    polyclinic.addAppointment(appointment);
    
    auto appointments = polyclinic.getAppointments();
    EXPECT_EQ(appointments.size(), 1);
    EXPECT_EQ(appointments[0]->getDate(), "2024-10-10");
}

TEST(PolyclinicTest, GetAllDoctorsSummary) 
{
    Polyclinic polyclinic;
    
    auto doctor1 = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto doctor2 = polyclinic.createDoctor("Анна", "Сидорова", 38, "Хирург", "10-18");
    
    polyclinic.addDoctor(doctor1);
    polyclinic.addDoctor(doctor2);
    
    auto summaries = polyclinic.getAllDoctorsSummary();
    EXPECT_EQ(summaries.size(), 2);
  
    EXPECT_NE(summaries[0].find("Иван Петров"), std::string::npos);
    EXPECT_NE(summaries[0].find("Терапевт"), std::string::npos);
}

TEST(PolyclinicTest, GetAllPatientsSummary) 
{
    Polyclinic polyclinic;
    
    auto patient1 = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    auto patient2 = polyclinic.createPatient("Мария", "Кузнецова", 25, "MC456");
    
    polyclinic.addPatient(patient1);
    polyclinic.addPatient(patient2);
    
    auto summaries = polyclinic.getAllPatientsSummary();
    EXPECT_EQ(summaries.size(), 2);
    
    EXPECT_NE(summaries[0].find("Сергей Иванов"), std::string::npos);
    EXPECT_NE(summaries[0].find("MC123"), std::string::npos);
}

TEST(PolyclinicTest, GetAllAppointmentsInfo) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto patient = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    
    polyclinic.addDoctor(doctor);
    polyclinic.addPatient(patient);
    
    auto appointment = polyclinic.createAppointment(doctor, patient, "2024-10-10", "10:00");
    polyclinic.addAppointment(appointment);
    
    auto appointmentsInfo = polyclinic.getAllAppointmentsInfo();
    EXPECT_EQ(appointmentsInfo.size(), 1);
    
    EXPECT_NE(appointmentsInfo[0].find("2024-10-10"), std::string::npos);
    EXPECT_NE(appointmentsInfo[0].find("10:00"), std::string::npos);
}

TEST(PolyclinicTest, GetAllPeoplePolymorphism) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto patient = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    
    polyclinic.addDoctor(doctor);
    polyclinic.addPatient(patient);
    
    auto allPeople = polyclinic.getAllPeople();
    EXPECT_EQ(allPeople.size(), 2);
    
    for (const auto& person : allPeople) 
    {
        std::string info = person->getInfo();
        EXPECT_FALSE(info.empty());
    }
}

TEST(PolyclinicTest, InvalidAddOperations) 
{
    Polyclinic polyclinic;
    
    EXPECT_THROW(polyclinic.addDoctor(nullptr), std::invalid_argument);
    EXPECT_THROW(polyclinic.addPatient(nullptr), std::invalid_argument);
    EXPECT_THROW(polyclinic.addAppointment(nullptr), std::invalid_argument);
}

TEST(PolyclinicTest, InvalidCreateAppointment) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    
    EXPECT_THROW(polyclinic.createAppointment(doctor, nullptr, "2024-10-10", "10:00"), 
                 std::invalid_argument);
    EXPECT_THROW(polyclinic.createAppointment(nullptr, nullptr, "2024-10-10", "10:00"), 
                 std::invalid_argument);
}

TEST(PolyclinicTest, AutoIncrementId) 
{
    Polyclinic polyclinic;
    
    auto doctor1 = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto doctor2 = polyclinic.createDoctor("Анна", "Сидорова", 38, "Хирург", "10-18");
    auto patient1 = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
 
    EXPECT_NE(doctor1->getId(), doctor2->getId());
    EXPECT_NE(doctor1->getId(), patient1->getId());
}

TEST(IntegrationTest, CompletePolyclinicWorkflow) 
{
    Polyclinic polyclinic;

    auto doctor1 = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    auto doctor2 = polyclinic.createDoctor("Анна", "Сидорова", 38, "Хирург", "10-18");
    
    polyclinic.addDoctor(doctor1);
    polyclinic.addDoctor(doctor2);

    auto patient1 = polyclinic.createPatient("Сергей", "Иванов", 30, "MC123");
    auto patient2 = polyclinic.createPatient("Мария", "Кузнецова", 25, "MC456");
    
    polyclinic.addPatient(patient1);
    polyclinic.addPatient(patient2);

    auto appointment1 = polyclinic.createAppointment(doctor1, patient1, "2024-10-10", "10:00");
    auto appointment2 = polyclinic.createAppointment(doctor2, patient2, "2024-10-11", "11:00");
    
    polyclinic.addAppointment(appointment1);
    polyclinic.addAppointment(appointment2);
    
    auto doctorsSummary = polyclinic.getAllDoctorsSummary();
    auto patientsSummary = polyclinic.getAllPatientsSummary();
    auto appointmentsInfo = polyclinic.getAllAppointmentsInfo();
    
    EXPECT_EQ(doctorsSummary.size(), 2);
    EXPECT_EQ(patientsSummary.size(), 2);
    EXPECT_EQ(appointmentsInfo.size(), 2);
    
    auto allPeople = polyclinic.getAllPeople();
    EXPECT_EQ(allPeople.size(), 4);
    
    int doctorCount = 0;
    int patientCount = 0;
    
    for (const auto& person : allPeople) {
        std::string info = person->getInfo();
        if (info.find("Врач") != std::string::npos) doctorCount++;
        if (info.find("Пациент") != std::string::npos) patientCount++;
    }
    
    EXPECT_EQ(doctorCount, 2);
    EXPECT_EQ(patientCount, 2);
}

TEST(EdgeCasesTest, EmptyPolyclinic) 
{
    Polyclinic polyclinic;
    
    auto doctorsSummary = polyclinic.getAllDoctorsSummary();
    auto patientsSummary = polyclinic.getAllPatientsSummary();
    auto appointmentsInfo = polyclinic.getAllAppointmentsInfo();
    auto allPeople = polyclinic.getAllPeople();
    
    EXPECT_TRUE(doctorsSummary.empty());
    EXPECT_TRUE(patientsSummary.empty());
    EXPECT_TRUE(appointmentsInfo.empty());
    EXPECT_TRUE(allPeople.empty());
}

TEST(EdgeCasesTest, DuplicateAdditions) 
{
    Polyclinic polyclinic;
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
   
    polyclinic.addDoctor(doctor);
    polyclinic.addDoctor(doctor);
    
    EXPECT_EQ(polyclinic.getAllPeople().size(), 2);
}

TEST(EdgeCasesTest, PersonInformationConsistency) 
{
    Doctor doctor(1, "Иван", "Петров", 45, "Терапевт", "Пн-Пт 9:00-17:00");
    
    EXPECT_EQ(doctor.getId(), 1);
    EXPECT_EQ(doctor.getFirstName(), "Иван");
    EXPECT_EQ(doctor.getLastName(), "Петров");
    EXPECT_EQ(doctor.getAge(), 45);
    EXPECT_EQ(doctor.getSpecialization(), "Терапевт");
    EXPECT_EQ(doctor.getSchedule(), "Пн-Пт 9:00-17:00");
    EXPECT_EQ(doctor.getFullName(), "Иван Петров");
   
    std::string info = doctor.getInfo();
    EXPECT_NE(info.find("1"), std::string::npos);
    EXPECT_NE(info.find("Иван"), std::string::npos);
    EXPECT_NE(info.find("Петров"), std::string::npos);
    EXPECT_NE(info.find("45"), std::string::npos);
    EXPECT_NE(info.find("Терапевт"), std::string::npos);
    EXPECT_NE(info.find("Пн-Пт 9:00-17:00"), std::string::npos);
}

TEST(ExceptionTest, PolyclinicInvalidArguments) 
{
    Polyclinic polyclinic;
    
    EXPECT_THROW(polyclinic.addDoctor(nullptr), std::invalid_argument);
    EXPECT_THROW(polyclinic.addPatient(nullptr), std::invalid_argument);
    EXPECT_THROW(polyclinic.addAppointment(nullptr), std::invalid_argument);
    
    auto doctor = polyclinic.createDoctor("Иван", "Петров", 45, "Терапевт", "9-17");
    EXPECT_THROW(polyclinic.createAppointment(doctor, nullptr, "2024-10-10", "10:00"), 
                 std::invalid_argument);
    EXPECT_THROW(polyclinic.createAppointment(nullptr, nullptr, "2024-10-10", "10:00"), 
                 std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}