#include <string>
#include<iostream>

#pragma once
class Car
{
private:
    std :: string brand;
    int year;
public:
    Car (const std::string brand, const int year);
    Car();
    ~Car() = default;

    friend std::ostream& operator<<(std::ostream& os, const Car& car);

};