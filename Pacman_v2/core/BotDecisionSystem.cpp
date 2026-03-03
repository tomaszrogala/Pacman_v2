#include "BotDecisionSystem.h"
#include "../state/GameState.h"
#include "ai/RandomStrategy.h"

namespace
{
    //ai dispatch
    using DecideFunctionPtr = Direction(*)(Ghost&, const GameState&);

    static constexpr DecideFunctionPtr g_ai_table[] = {
        &RandomStrategy::decide,         // GhostAIType::Random
        //&DijkstraStrategy::decide   // GhostAIType::DijkstraChase
    };
}

void BotDecisionSystem::update(GameState& a_state) const
{
    for (Ghost& ghost : a_state.m_Ghosts)
    {
        const int idx = static_cast<int>(ghost.m_AiType);
        ghost.m_Direction = g_ai_table[idx](ghost, a_state);
    }
}
