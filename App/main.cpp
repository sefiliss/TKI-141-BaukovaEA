#include <iostream>
#include <memory>
#include "../Lib/Task_1.h"
#include "../Lib/Task_2.h"
#include "../Lib/Task_3.h"
#include "../Lib/RandomGenerate.h"
#include "../Lib/ConstantGenerate.h"
#include "../Lib/IStreamGenerate.h"

int main()
{
    const size_t size = 10;

    std::unique_ptr<Matrix> matrix = std::make_unique<Matrix>(size);

    std::unique_ptr<Task_1> task_1 = std::make_unique<Task_1>(std::move(matrix));

    task_1->fill_matrix();
    task_1->Task();
    std::unique_ptr<Matrix> matrix_2 = std::make_unique<Matrix>(size);
    std::unique_ptr<Task_2> task_2 = std::make_unique<Task_2>(std::move(matrix), 2, 5);

    task_2->fill_matrix();
    task_2->Task();
    std::unique_ptr<Matrix> matrix_3 = std::make_unique<Matrix>(size);
    std::unique_ptr<Task_3> task_3 = std::make_unique<Task_3>(std::move(matrix));

    task_3->fill_matrix();
    task_3->Task();

    return 0;
}
