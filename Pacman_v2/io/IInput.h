#pragma once
#include "../utils/Direction.h"

class IInput 
{
public:
    virtual ~IInput() = default;
    virtual Direction read_direction() = 0;
};
