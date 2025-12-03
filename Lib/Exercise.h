#pragma once
#include <memory>
#include <string>
#include "Matrix.h"
#include "Generator.h"

class Exercise
{
protected:
    std::unique_ptr<Matrix> matrix;
    std::unique_ptr<Generator> generator;

public:
    Exercise(std::unique_ptr<Matrix> matr, std::unique_ptr<Generator> gen): matrix(std::move(matr)), generator(std::move(gen)){};
    void fill_matrix();
    virtual void Task() = 0;
    virtual ~Exercise() = default;
    std::string get_string_matrix() const;
};
