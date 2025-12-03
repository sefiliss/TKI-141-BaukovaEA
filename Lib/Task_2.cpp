#include "Task_2.h"
#include <stdexcept>
#include <iostream>

Task_2::Task_2(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator, size_t from, size_t to)
{
    this->matrix = std::move(matrix);
    this->generator = std::move(generator);
    this->from = from;
    this->to = to;
}

void Task_2::Task()
{
    int count_delete = 0;

    for(size_t i = from; i < to; i++)
    {
        if((*matrix)[i] % 7 == 0)
        {
            delete_element(i);
            count_delete += 1;
        }
    }

    for(size_t i = 0; i <= count_delete; i++)
    {
        (*matrix)[matrix->get_size() - i] = 0;
    }
}

void Task_2::delete_element(size_t index)
{
    for(size_t i = index; i < this->matrix->get_size() - 1; i++)
    {
        (*matrix)[i] = (*matrix)[i+1];
    }
}
