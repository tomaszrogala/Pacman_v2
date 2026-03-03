#pragma once
#include <queue>
#include <vector>
#include <limits>
#include "../../utils/Direction.h"

struct Ghost;
struct GameState;

class DijkstraStrategy
{
  public:
    static Direction decide(Ghost& a_ghost, const GameState& a_state);
};
