#include "BotDecisionSystem.h"
#include "../state/GameState.h"
#include "ai/RandomStrategy.h"

namespace
{
    //ai dispatch
    using DecideFunctionPtr = Direction(*)(Ghost&, const GameState&);

    static constexpr DecideFunctionPtr g_ai_table[] = {
        &RandomStrategy::decide,         // GhostAIType::Random
        //&DijkstraChaseStrategy::decide   // GhostAIType::DijkstraChase
    };
}

void BotDecisionSystem::update(GameState& state) const
{
    for (Ghost& ghost : state.m_ghosts)
    {
        const int idx = static_cast<int>(ghost.m_ai_type);
        ghost.m_direction = g_ai_table[idx](ghost, state);
    }
}
