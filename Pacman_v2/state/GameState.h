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
    Map m_Map;
    Pacman m_Pacman;
    std::vector<Ghost> m_Ghosts;
    std::vector<Pellet> m_Pellets;
    
    GameState(const GameConfig& a_config);
};
