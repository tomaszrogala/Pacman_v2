#include "RandomStrategy.h"
#include "../../entities/Ghost.h"
#include "../../state/GameState.h"

Direction RandomStrategy::decide(Ghost& a_ghost, const GameState& a_state)
{
    if (is_dead_end(a_ghost, a_state))
    {
        return get_opposite(a_ghost.m_direction);
    }

    if (!is_crossroad(a_ghost, a_state))
    {
        return a_ghost.m_direction;
    }

    std::vector<Direction> valid_dir = {
       Direction::Up,
       Direction::Down,
       Direction::Left,
       Direction::Right
    };

    auto opposite = get_opposite(a_ghost.m_direction); //TODO: Prevent from wall directions
    valid_dir.erase(std::remove(valid_dir.begin(), valid_dir.end(), opposite), valid_dir.end());

    std::uniform_int_distribution<int> distribution(0, valid_dir.size() - 1);
    return valid_dir[distribution(Random::rng)];
}

Direction RandomStrategy::get_opposite(Direction a_direction)
{
    switch (a_direction)
    {
    case Direction::Down: return Direction::Up;
    case Direction::Up: return Direction::Down;
    case Direction::Right: return Direction::Left;
    case Direction::Left: return Direction::Right;
    }

    return Direction::None;
}

bool RandomStrategy::is_crossroad(Ghost& a_ghost, const GameState& a_state)
{
    if (a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x + 1, a_ghost.m_position.y }) &&
        a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x - 1, a_ghost.m_position.y }))
    {
        return false;
    }

    if (a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x, a_ghost.m_position.y + 1 }) &&
        a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x, a_ghost.m_position.y - 1 }))
    {
        return false;
    }

    return true;
}
                                                                                                 
bool RandomStrategy::is_dead_end(Ghost& a_ghost, const GameState& a_state)
{                                                                         
    int wall_count = 0;

    wall_count += a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x + 1, a_ghost.m_position.y });
    wall_count += a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x - 1, a_ghost.m_position.y });
    wall_count += a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x, a_ghost.m_position.y + 1 });
    wall_count += a_state.m_map.is_wall(Position2D{ a_ghost.m_position.x, a_ghost.m_position.y - 1 });

    return wall_count >= 3;
}
