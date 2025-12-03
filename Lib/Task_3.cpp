#include "Task_3.h"
#include <cmath>
#include <iostream>

Task_3::Task_3(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
{
    this->matrix = std::move(matrix);
    this->generator = std::move(generator);
}

void Task_3::Task()
{
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
}
