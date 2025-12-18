#pragma once 
#include "Exercise.h"

class Task_3: public Exercise
{
public:
    Task_3(std::unique_ptr<Matrix> matrix);
    void Task() override;
};
