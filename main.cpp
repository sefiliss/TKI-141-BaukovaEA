#include <memory>
#include "Car.h"
int main()
{
    std::shared_ptr <Car> carPtr (new Car("Toyota", 2025));
    std::cout << *carPtr << std::endl;

    std::shared_ptr <Car> otherCarPtr;
    otherCarPtr = carPtr;
    std::cout << *otherCarPtr << std::endl;
    std::cout << *carPtr << std::endl;

    return 0;
}