#pragma once 
#include "Exercise.h"

class Task_2: public Exercise
{
private:
    void delete_element(size_t index);
    size_t from;
    size_t to;
public:
    Task_2(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator, size_t from, size_t to);
    void Task() override;
};
