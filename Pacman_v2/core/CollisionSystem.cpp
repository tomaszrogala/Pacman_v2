#include "CollisionSystem.h"
#include "../state/GameState.h"

void CollisionSystem::update(GameState& a_state) const
{
    auto& pacman_position = a_state.m_pacman.m_position;

    if (a_state.m_map.is_pellet(pacman_position))
    {
        a_state.m_map.erase_tile(pacman_position);
    }

    if (a_state.m_map.is_power_pellet(pacman_position))
    {
        a_state.m_map.erase_tile(pacman_position);
        //TODO: change pacman state
    }

    for (auto& ghost : a_state.m_ghosts)
    {
        //TODO: if super pacman state, erase the ghost
        if (ghost.m_position == pacman_position)
        {
            std::exit(0);
        }
    }
}