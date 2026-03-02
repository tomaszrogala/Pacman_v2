#include "MovementSystem.h"
#include "../state/GameState.h"

void MovementSystem::update(GameState& a_state) const
{
    try_move(a_state.m_map, a_state.m_pacman.m_direction, a_state.m_pacman.m_position);

    for (auto& ghost : a_state.m_ghosts)
        try_move(a_state.m_map, ghost.m_direction, ghost.m_position);
}

bool MovementSystem::try_move(const Map& a_map, Direction a_direction, Position2D& a_position) const
{
    Position2D next = a_position;

    switch (a_direction)
    {
    case Direction::Up:    --next.y; break;
    case Direction::Down:  ++next.y; break;
    case Direction::Left:  --next.x; break;
    case Direction::Right: ++next.x; break;
    case Direction::None:  return false;
    }

    if (a_map.is_wall(next))
        return false;

    a_position = next;
    return true;
}

