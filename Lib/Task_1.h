#pragma once 
#include <iostream>
#include "Exercise.h"

class Task_1: public Exercise
{
private:
    int& find_negative() const;
    int& find_positive() const;
public:
    Task_1(std::unique_ptr<Matrix> matrix): Exercise(std::move(matrix)){};
    void Task() override;
};
