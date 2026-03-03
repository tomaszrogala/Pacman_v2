#pragma once
#include "Tile.h"
#include "../utils/Position2D.h"
#include <vector>

struct Map
{
    //TODO: Add width and height 
    std::vector<std::vector<Tile>> m_Tiles;

    int height() const
    { 
        return m_Tiles.size();
    };

    int width() const
    { 
        return m_Tiles[0].size(); 
    };

    void erase_tile(Position2D a_position)
    {
        m_Tiles[a_position.m_Y][a_position.m_X] = Tile::Empty;
    };

    bool is_wall(Position2D a_position) const 
    {
        return m_Tiles[a_position.m_Y][a_position.m_X] == Tile::Wall;
    };

    bool is_pellet(Position2D a_position) const
    {
        return m_Tiles[a_position.m_Y][a_position.m_X] == Tile::Pellet;
    };

    bool is_power_pellet(Position2D a_position) const
    {
        return m_Tiles[a_position.m_Y][a_position.m_X] == Tile::PowerPellet;
    };
};
