#include <cstdlib>
#include "Matrix.h"

Matrix::Matrix(const Matrix& other)
{
    data = std::make_unique<int[]>(other.size);
    size = other.size;
    for(size_t i = 0; i < size; i++)
    {
        data[i] = other[i];
    }
}

Matrix& Matrix::operator=(const Matrix& other)
{
    is_this_matrix(other);

    if(size == 0)
    {
        data = std::make_unique<int[]>(other.size);
    }

    size = other.size;

    for(size_t i = 0; i < size; i++)
    {
        data[i] = other[i];
    }
    
    return *this;
}

int& Matrix::operator[](const size_t index)
{
    if(index >= size)
    {
        throw std::out_of_range("Index should be less than size");
    }

    return data[index];
}

const int& Matrix::operator[](const size_t index) const
{
    if(index >= size)
    {
        throw std::out_of_range("Index should be less than size");
    }

    return data[index];
}

size_t Matrix::get_size() const
{
    return size;
}

const std::string Matrix::get_string() const
{
    is_empty();

    std::string str_matrix = "[ ";
    
    for(size_t i = 0; i < size; i++)
    {
        str_matrix += std::to_string(data[i]);
        if(i != size - 1)
        {
            str_matrix += ", ";
        }
    }
    
    str_matrix += " ]";
    return str_matrix;
}

const void Matrix::is_empty() const
{
    if(size == 0)
    {
        throw std::invalid_argument("List is empty");
    }
}

const void Matrix::is_this_matrix(const Matrix& other) const
{
    if(this == &other)
    {
        throw std::domain_error("Error");
    }
}
