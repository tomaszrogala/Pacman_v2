#pragma once
#include "../utils/Position2D.h"

struct GameConfig;
struct GameState;
struct Map;

class GameInitializer
{
public:
    static void initialize(GameState& a_state, const GameConfig& a_config);

private:
    static Position2D find_first_walkable_position(const Map& a_map);
    static Position2D find_ghost_spawn_position(const Map& a_map);
};
