#pragma once 
#include <memory>
#include <stdexcept>
#include <string>
#include "Generator.h"

class Matrix
{
private:
    std::unique_ptr<int[]> data = nullptr;
    size_t size;
    const void is_empty() const;
    const void is_this_matrix(const Matrix& other) const;
public:
    Matrix(): size(0){};
    explicit Matrix(size_t size): size(size), data(std::make_unique<int[]>(size)){};
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept = default;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept = default;
    ~Matrix() = default;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    size_t get_size() const;
    const std::string get_string() const; 
};
