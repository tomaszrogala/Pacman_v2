#pragma once

struct Position2D 
{
    int x;
    int y;

    bool operator == (const Position2D& a_right) const
    {
        return a_right.x == this->x && a_right.y == this->y;
    }
};