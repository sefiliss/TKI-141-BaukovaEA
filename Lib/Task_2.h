#pragma once 
#include "Exercise.h"

class Task_2: public Exercise
{
private:
    void delete_element(const size_t count_delete);
    size_t from;
    size_t to;
public:
    Task_2(std::unique_ptr<Matrix> matrix, size_t from, size_t to);
    void Task() override;
};
