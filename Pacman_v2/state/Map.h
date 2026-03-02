#pragma once
#include "Tile.h"
#include "../utils/Position2D.h"

#include <vector>

struct Map
{
	std::vector<std::vector<Tile>> m_tiles;

    void erase_tile(Position2D a_position)
    {
        m_tiles[a_position.y][a_position.x] = Tile::Empty;
    };

	bool is_wall(Position2D a_position) const 
	{
		return m_tiles[a_position.y][a_position.x] == Tile::Wall;
	};

	bool is_pellet(Position2D a_position) const
	{
		return m_tiles[a_position.y][a_position.x] == Tile::Pellet;
	};

	bool is_power_pellet(Position2D a_position) const
	{
		return m_tiles[a_position.y][a_position.x] == Tile::PowerPellet;
	};
};