#include "Task_1.h"

void Task_1::Task()
{
    if(generator == nullptr)
    {
        exit(1);
    }

    std::cout << "Matrix before:\n" << matrix->get_string() << std::endl;

    try{
        int& a = find_negative();
        int& b = find_positive();

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        std::cout << "Matrix after:\n" << matrix->get_string() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error " << e.what() << '\n';
    }
}

int& Task_1::find_negative() const
{
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        if((*matrix)[i] < 0)
        {
            return (*matrix)[i];
        }
    }

    throw std::domain_error("No negative element found");
}

int& Task_1::find_positive() const
{
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        if((*matrix)[i] > 0)
        {
            return (*matrix)[i];
        }
    }

    throw std::domain_error("No positive element found");
}
