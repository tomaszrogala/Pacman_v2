#pragma once
#include "IInput.h"

enum class Direction;

class ConsoleInputAsync : public IInput 
{
public:
    ConsoleInputAsync();
    Direction read_direction() override;
private:
    Direction m_current_direction;
    
};