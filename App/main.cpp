#include <iostream>
#include <memory>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "RandomGenerate.h"
#include "ConstantGenerate.h"
#include "IStreamGenerate.h"

int main()
{
    const size_t size = 10;
    
    auto matrix1 = std::make_unique<Matrix>(size);
    auto generator1 = std::make_unique<RandomGenerate>(-100, 100);
    auto task1 = std::make_unique<Task_1>(std::move(matrix1), std::move(generator1));
    task1->fill_matrix();
    std::cout << "Before Task_1: " << task1->get_string_matrix() << std::endl;
    task1->Task();
    std::cout << "After Task_1: " << task1->get_string_matrix() << std::endl;
    
    auto matrix2 = std::make_unique<Matrix>(size);
    auto generator2 = std::make_unique<ConstantGenerate>(7);
    auto task2 = std::make_unique<Task_2>(std::move(matrix2), std::move(generator2), 0, size);
    task2->fill_matrix();
    std::cout << "Before Task_2: " << task2->get_string_matrix() << std::endl;
    task2->Task();
    std::cout << "After Task_2: " << task2->get_string_matrix() << std::endl;
    
    auto matrix3 = std::make_unique<Matrix>(size);
    auto generator3 = std::make_unique<IStreamGenerate>();
    auto task3 = std::make_unique<Task_3>(std::move(matrix3), std::move(generator3));
    task3->fill_matrix();
    std::cout << "Before Task_3: " << task3->get_string_matrix() << std::endl;
    task3->Task();
    std::cout << "After Task_3: " << task3->get_string_matrix() << std::endl;
    
    return 0;
}
