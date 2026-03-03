#include "RandomStrategy.h"
#include "../../entities/Ghost.h"
#include "../../state/GameState.h"

Direction RandomStrategy::decide(Ghost& a_ghost, const GameState& a_state)
{
    if (is_dead_end(a_ghost, a_state))
    {
        return get_opposite(a_ghost.m_Direction);
    }

    if (!is_crossroad(a_ghost, a_state))
    {
        return a_ghost.m_Direction;
    }

    std::vector<Direction> validDir = {
       Direction::Up,
       Direction::Down,
       Direction::Left,
       Direction::Right
    };

    auto opposite = get_opposite(a_ghost.m_Direction); //TODO: Prevent from wall directions
    validDir.erase(std::remove(validDir.begin(), validDir.end(), opposite), validDir.end());

    std::uniform_int_distribution<int> distribution(0, static_cast<int>(validDir.size()) - 1);
    return validDir[distribution(Random::rng)];
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
    if (a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X + 1, a_ghost.m_Position.m_Y }) &&
        a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X - 1, a_ghost.m_Position.m_Y }))
    {
        return false;
    }

    if (a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X, a_ghost.m_Position.m_Y + 1 }) &&
        a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X, a_ghost.m_Position.m_Y - 1 }))
    {
        return false;
    }

    return true;
}
                                                                                                 
bool RandomStrategy::is_dead_end(Ghost& a_ghost, const GameState& a_state)
{
    int wallCount = 0;

    wallCount += a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X + 1, a_ghost.m_Position.m_Y });
    wallCount += a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X - 1, a_ghost.m_Position.m_Y });
    wallCount += a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X, a_ghost.m_Position.m_Y + 1 });
    wallCount += a_state.m_Map.is_wall(Position2D{ a_ghost.m_Position.m_X, a_ghost.m_Position.m_Y - 1 });

    return wallCount >= 3;
}
