#pragma once 

class Generator
{
public:
    Generator();
    virtual int generate() = 0;
    virtual ~Generator() = default;
};
