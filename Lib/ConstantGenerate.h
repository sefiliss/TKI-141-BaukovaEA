#pragma once 
#include "Generator.h"

class ConstantGenerate: public Generator
{
private:
    int value;

public:
    int generate() override;
    ~ConstantGenerate() = default;
    ConstantGenerate(const int value): value(value){};
};
