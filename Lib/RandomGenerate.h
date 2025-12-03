#pragma once
#include <stdexcept>
#include <random>
#include "Generator.h"

class RandomGenerate: public Generator
{
private:
    int min, max;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;
public:
    ~RandomGenerate() = default;
    int generate() override;
    RandomGenerate(const int min, const int max);
};
