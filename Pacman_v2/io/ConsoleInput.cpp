#include <conio.h>
#include <iostream>
#include <Windows.h>

#include "ConsoleInput.h"
#include "../utils/Direction.h"

ConsoleInputAsync::ConsoleInputAsync()
    : m_current_direction(Direction::None)
{
}

Direction ConsoleInputAsync::read_direction() 
{
    // Check current key state – no blocking, no repeat delay
    if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('A') & 0x8000) m_current_direction = Direction::UpLeft;
    if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('D') & 0x8000) m_current_direction = Direction::UpRight;
    if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('A') & 0x8000) m_current_direction = Direction::DownLeft;
    if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('D') & 0x8000) m_current_direction = Direction::DownRight;
    if (GetAsyncKeyState('W') & 0x8000) m_current_direction = Direction::Up;
    if (GetAsyncKeyState('S') & 0x8000) m_current_direction = Direction::Down;
    if (GetAsyncKeyState('A') & 0x8000) m_current_direction = Direction::Left;
    if (GetAsyncKeyState('D') & 0x8000) m_current_direction = Direction::Right;
    if (GetAsyncKeyState('Q') & 0x8000) std::exit(0);        

    return m_current_direction;
}
