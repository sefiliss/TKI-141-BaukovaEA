#include "Task_2.h"
#include <stdexcept>
#include <iostream>

Task_2::Task_2(std::unique_ptr<Matrix> matrix, size_t from, size_t to): Exercise(std::move(matrix)), from(from), to(to)
{
    
}

void Task_2::Task()
{
    if(generator == nullptr)
    {
        exit(1);
    }

    std::cout << "Matrix before:\n" << matrix->get_string() << std::endl;
    int count_delete = 0;

    for(size_t i = from; i < to; i++)
    {
        if((*matrix)[i] % 7 == 0)
        {
            (*matrix)[i] = NULL;
            count_delete += 1;
        }
    }

    delete_element(count_delete);

    std::cout << "Matrix after:\n" << matrix->get_string() << std::endl;
}

void Task_2::delete_element(const size_t count_delete)
{
    std::unique_ptr<Matrix> new_matrix = std::make_unique<Matrix>(matrix->get_size() - count_delete);
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        size_t new_matrix_index = 0;

        if((*matrix)[i] != NULL)
        {
            (*new_matrix)[new_matrix_index] = (*matrix)[i];
            new_matrix_index += 1;
        }
    }

    matrix = std::move(new_matrix);
}
