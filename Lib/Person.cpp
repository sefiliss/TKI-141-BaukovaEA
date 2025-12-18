#include "Person.h"
#include <sstream>

Person::Person(int id, const std::string& firstName,
               const std::string& lastName, int age)
    : id(id), firstName(firstName), lastName(lastName), age(age) {}

int Person::getId() const 
{ 
    return id; 
}
std::string Person::getFirstName() const 
{ 
    return firstName; 
}
std::string Person::getLastName() const 
{ 
    return lastName; 
}
int Person::getAge() const 
{ 
    return age; 
}

std::string Person::getFullName() const 
{
    std::ostringstream oss;
    oss << firstName << " " << lastName;
    return oss.str();
}