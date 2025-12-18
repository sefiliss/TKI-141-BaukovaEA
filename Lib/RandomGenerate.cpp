#include "RandomGenerate.h"

RandomGenerate::RandomGenerate(const int min, const int max)
{
    if(min >= max)
    {
        throw std::invalid_argument("Error: min >= max");
    }

    this->gen = std::mt19937(std::random_device{}());
    this->min = min;
    this->max = max;
    this->dist = std::uniform_int_distribution<int>(min, max);
}

int RandomGenerate::generate()
{
    int value = dist(gen);
    return value;
}
