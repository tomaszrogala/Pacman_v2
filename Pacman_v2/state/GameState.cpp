#include "GameState.h"
#include "GameConfig.h"
#include "../helpers/GameInitializer.h"

GameState::GameState(const GameConfig& a_config)
{
    GameInitializer::initialize(*this, a_config);
}