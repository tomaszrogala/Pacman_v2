#include "GameInitializer.h"
#include "MapLoader.h"
#include "../state/GameConfig.h"
#include "../state/GameState.h"
#include "../entities/Pacman.h"

#include <stdexcept>


void GameInitializer::initialize(GameState& a_state, const GameConfig& a_config) //TODO:
{
    a_state.m_Map = MapLoader::load_from_file(a_config.m_map_file_path);

    const int height = static_cast<int>(a_state.m_Map.m_Tiles.size());
    const int width = height > 0 ? static_cast<int>(a_state.m_Map.m_Tiles[0].size()) : 0;

    if (width == 0 || height == 0)
        throw std::runtime_error("GameInitializer: loaded map has invalid size");

    // Pacman spawn
    a_state.m_Pacman.m_Position = find_first_walkable_position(a_state.m_Map);

    // Ghosts spawn 
    a_state.m_Ghosts.push_back(Ghost{ Direction::Left, find_ghost_spawn_position(a_state.m_Map), AiType::RANDOM });
    a_state.m_Ghosts.push_back(Ghost{ Direction::Left, find_ghost_spawn_position(a_state.m_Map), AiType::RANDOM });
    a_state.m_Ghosts.push_back(Ghost{ Direction::Left, find_ghost_spawn_position(a_state.m_Map), AiType::DIJKSTRA });

    // Pellets 
    a_state.m_Pellets.clear();
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const Tile t = a_state.m_Map.m_Tiles[y][x];
            if (t == Tile::Pellet || t == Tile::PowerPellet)
            {
                a_state.m_Pellets.push_back(Pellet{ Position2D{ x, y } });
            }
        }
    }
}

Position2D GameInitializer::find_first_walkable_position(const Map& a_map)
{
    const int h = static_cast<int>(a_map.m_Tiles.size());
    const int w = h > 0 ? static_cast<int>(a_map.m_Tiles[0].size()) : 0;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (a_map.m_Tiles[y][x] != Tile::Wall)
                return Position2D{ x, y };
        }
    }

    throw std::runtime_error("GameInitializer: no walkable tile found in map");
}

Position2D GameInitializer::find_ghost_spawn_position(const Map& a_map)
{
    const int h = static_cast<int>(a_map.m_Tiles.size());
    const int w = h > 0 ? static_cast<int>(a_map.m_Tiles[0].size()) : 0;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (a_map.m_Tiles[y][x] == Tile::GhostDoor)
                return Position2D{ x, y };
        }
    }

    throw std::runtime_error("GameInitializer: no ghost door tile found in map");
}
