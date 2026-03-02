#pragma once

class GameState;
struct Map;
enum class Direction;
struct Position2D;

class MovementSystem 
{
public:
	void update(GameState& a_state) const;

private:
	bool try_move(const Map& a_map, Direction a_direction, Position2D& a_position) const;
};

