#include"Car.h"

Car::Car(const std::string brand, const int year) :brand(brand), year(year)
{

}

Car::Car()
{
    brand = " ";
    year = 1900;
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << car.brand << " " << car.year;
    return os;
}
