#pragma once

enum class Tile
{
    Empty,
    Wall,
    Pellet,
    PowerPellet,
    GhostDoor
};

inline char tile_to_char(Tile a_tile)
{
    switch (a_tile)
    {
    case Tile::Wall:         return '#';
    case Tile::Pellet:       return '.';
    case Tile::PowerPellet:  return 'o';
    case Tile::GhostDoor:    return 'A';
    default:                 return ' ';
    }
}

inline Tile tile_from_char(char c)
{
    switch (c)
    {
    case '#': return Tile::Wall;
    case '.': return Tile::Pellet;
    case 'o': return Tile::PowerPellet;
    case 'A': return Tile::GhostDoor;
    default:  return Tile::Empty;
    }
}
