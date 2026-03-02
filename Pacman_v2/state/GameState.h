#pragma once
#include <random>
#include "../entities/Pacman.h"
#include "../entities/Ghost.h"
#include "../state/Map.h"
#include "../state/Pellet.h"

struct GameConfig;
namespace Random 
{
    inline std::random_device rd;
    inline std::mt19937 rng{ rd() };
}

struct GameState 
{ 
    Map m_map;
    Pacman m_pacman;
    std::vector<Ghost> m_ghosts;
    std::vector<Pellet> m_pellets;
    
    GameState(const GameConfig& a_config);
};
