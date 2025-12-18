#pragma once
#include <string>
#include <memory>

class Person 
{
private:
    int id;
    std::string firstName;
    std::string lastName;
    int age;

protected:
    Person(int id, const std::string& firstName, 
           const std::string& lastName, int age);

public:
    virtual ~Person() = default;
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    std::string getFullName() const;
    virtual std::string getInfo() const = 0;
};