#pragma once

enum class Direction;
struct Ghost;
struct GameState;

class RandomStrategy
{
public:
    static Direction decide(Ghost& a_ghost, const GameState& a_state);
private:
    static Direction get_opposite(Direction a_direction);
    static bool      is_crossroad(Ghost& a_ghost, const GameState& a_state);
    static bool      is_dead_end(Ghost& a_ghost, const GameState& a_state);
};
