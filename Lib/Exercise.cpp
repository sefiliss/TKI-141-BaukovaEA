#include "Exercise.h"

void Exercise::fill_matrix()
{
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        (*matrix)[i] = generator->generate();
    }
}

std::string Exercise::get_string_matrix() const
{
    return matrix->get_string();
}
