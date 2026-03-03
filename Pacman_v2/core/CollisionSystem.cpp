#include "CollisionSystem.h"
#include "../state/GameState.h"

void CollisionSystem::update(GameState& a_state) const
{
    auto& pacmanPosition = a_state.m_Pacman.m_Position;

    if (a_state.m_Map.is_pellet(pacmanPosition))
    {
        a_state.m_Map.erase_tile(pacmanPosition);
    }

    if (a_state.m_Map.is_power_pellet(pacmanPosition))
    {
        a_state.m_Map.erase_tile(pacmanPosition);
        //TODO: change pacman state
    }

    for (auto& ghost : a_state.m_Ghosts)
    {
        //TODO: if super pacman state, erase the ghost
        if (ghost.m_Position == pacmanPosition)
        {
            std::exit(0);
        }
    }
}