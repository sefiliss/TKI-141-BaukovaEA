#include "Task_3.h"
#include <cmath>
#include <iostream>

Task_3::Task_3(std::unique_ptr<Matrix> matrix) : Exercise(std::move(matrix))
{
    
}

void Task_3::Task()
{
    std::cout << "Matrix before:\n" << matrix->get_string() << std::endl;
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        if(i % 2 == 0)
        {
            (*matrix)[i] = pow((*matrix)[i], 2) + i;
        }
        else {
            (*matrix)[i] *= i;
        }
    }
    std::cout << "Matrix after:\n" << matrix->get_string() << std::endl;
}
