#pragma once 

class Generator
{
public:
    Generator()=default;
    virtual int generate() = 0;
    virtual ~Generator() = default;
};
