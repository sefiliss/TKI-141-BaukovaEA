#pragma once
#include <memory>
#include <string>
#include "Matrix.h"
#include "Generator.h"
#include "RandomGenerate.h"
#include "IStreamGenerate.h"
#include "ConstantGenerate.h"

class Exercise
{
private:
    int int_input();
    void choose_func();
protected:
    std::unique_ptr<Matrix> matrix;
    std::unique_ptr<Generator> generator;

public:
    Exercise(std::unique_ptr<Matrix> matr): matrix(std::move(matr)){};
    virtual void Task() = 0;
    virtual ~Exercise() = default;
    std::string get_string_matrix() const;
    void fill_matrix();
};
