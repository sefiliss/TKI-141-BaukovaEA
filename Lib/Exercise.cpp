#include <iostream>
#include <limits>
#include "Exercise.h"

void Exercise::fill_matrix()
{
    choose_func();
    for(size_t i = 0; i < matrix->get_size(); i++)
    {
        (*matrix)[i] = generator->generate();
    }
}

std::string Exercise::get_string_matrix() const
{
    return matrix->get_string();
}

int Exercise::int_input()
{
    int number = 0;

    if(std::cin >> number)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        puts("Fail in input");
        exit(1);
    }

    return number;
}


void Exercise::choose_func()
{
    choose ch = (choose)int_input();

    switch (ch) {

        case randm:
            {
            std::unique_ptr<RandomGenerate> generate = std::make_unique<RandomGenerate>(-100, 100);
            generator = std::move(generator);
            break;
            }
        case manual:
            {
            std::unique_ptr<IStreamGenerate> generator = std::make_unique<IStreamGenerate>(std::cin);
            generator = std::move(generator);
            break;
            }
        case constant:
            {
                std::unique_ptr<ConstantGenerate> generator = std::make_unique<ConstantGenerate>(10);
                generator = std::move(generator);
                break;
            }
        default:
            puts("Invalid input generator");
    }
}
