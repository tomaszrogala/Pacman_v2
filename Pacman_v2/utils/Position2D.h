#pragma once

struct Position2D 
{
    int m_X;
    int m_Y;

    bool operator == (const Position2D& a_right) const
    {
        return a_right.m_X == this->m_X && a_right.m_Y == this->m_Y;
    }
};
