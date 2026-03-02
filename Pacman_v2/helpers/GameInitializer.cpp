#include "GameInitializer.h"
#include "MapLoader.h"
#include "../state/GameConfig.h"
#include "../state/GameState.h"
#include "../entities/Pacman.h"

#include <stdexcept>


void GameInitializer::initialize(GameState& state, const GameConfig& config) //TODO:
{
    state.m_map = MapLoader::load_from_file(config.m_map_file_path);

    const int height = static_cast<int>(state.m_map.m_tiles.size());
    const int width = height > 0 ? static_cast<int>(state.m_map.m_tiles[0].size()) : 0;

    if (width == 0 || height == 0)
        throw std::runtime_error("GameInitializer: loaded map has invalid size");

    // Pacman spawn
    state.m_pacman.m_position = find_first_walkable_position(state.m_map);

    // Ghosts spawn 
    state.m_ghosts.push_back(Ghost{ Direction::Left, find_ghost_spawn_position(state.m_map), AiType::RANDOM });
    state.m_ghosts.push_back(Ghost{ Direction::Left, find_ghost_spawn_position(state.m_map), AiType::RANDOM });

    // Pellets 
    state.m_pellets.clear();
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const Tile t = state.m_map.m_tiles[y][x];
            if (t == Tile::Pellet || t == Tile::PowerPellet)
            {
                state.m_pellets.push_back(Pellet{ Position2D{ x, y } });
            }
        }
    }
}

Position2D GameInitializer::find_first_walkable_position(const Map& map)
{
    const int h = static_cast<int>(map.m_tiles.size());
    const int w = h > 0 ? static_cast<int>(map.m_tiles[0].size()) : 0;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (map.m_tiles[y][x] != Tile::Wall)
                return Position2D{ x, y };
        }
    }

    throw std::runtime_error("GameInitializer: no walkable tile found in map");
}

Position2D GameInitializer::find_ghost_spawn_position(const Map& map)
{
    const int h = static_cast<int>(map.m_tiles.size());
    const int w = h > 0 ? static_cast<int>(map.m_tiles[0].size()) : 0;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (map.m_tiles[y][x] == Tile::GhostDoor)
                return Position2D{ x, y };
        }
    }

    throw std::runtime_error("GameInitializer: no ghost door tile found in map");
}
