#pragma once 
#include <iostream>
#include "Generator.h"

class IStreamGenerate: public Generator
{
private:
    std::istream& in;
    int int_input(const std::string& message = "");
public:
    IStreamGenerate(std::istream& in = std::cin): in(in){};
    ~IStreamGenerate() = default;
    int generate() override;
};
