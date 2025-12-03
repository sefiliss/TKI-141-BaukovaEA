#pragma once 

class Generator
{
public:
    virtual int generate() = 0;
    virtual ~Generator() = default;
};
