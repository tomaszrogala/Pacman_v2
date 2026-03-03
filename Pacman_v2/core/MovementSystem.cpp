#include "MovementSystem.h"
#include "../state/GameState.h"

void MovementSystem::update(GameState& a_state) const
{
    try_move(a_state.m_Map, a_state.m_Pacman.m_Direction, a_state.m_Pacman.m_Position);

    for (auto& ghost : a_state.m_Ghosts)
        try_move(a_state.m_Map, ghost.m_Direction, ghost.m_Position);
}

bool MovementSystem::try_move(const Map& a_map, Direction a_direction, Position2D& a_position) const
{
    Position2D next = a_position;

    switch (a_direction)
    {
    case Direction::Up:    --next.m_Y; break;
    case Direction::Down:  ++next.m_Y; break;
    case Direction::Left:  --next.m_X; break;
    case Direction::Right: ++next.m_X; break;
    case Direction::None:  return false;
    }

    if (a_map.is_wall(next))
        return false;

    a_position = next;
    return true;
}

