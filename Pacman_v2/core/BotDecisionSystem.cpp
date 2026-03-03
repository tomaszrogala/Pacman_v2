#include "BotDecisionSystem.h"
#include "../state/GameState.h"
#include "ai/RandomStrategy.h"
#include "ai/DijkstraStrategy.h"

namespace
{
    //ai dispatch
    using DecideFunctionPtr = Direction(*)(Ghost&, const GameState&);

    static constexpr DecideFunctionPtr g_ai_table[] = {
        &RandomStrategy::decide,         // GhostAIType::Random
        &DijkstraStrategy::decide       // GhostAIType::DijkstraChase
    };
}

void BotDecisionSystem::update(GameState& a_state) const
{
    for (Ghost& ghost : a_state.m_Ghosts)
    {
        ghost.m_Direction = g_ai_table[static_cast<int>(ghost.m_AiType)](ghost, a_state);
    }
}
