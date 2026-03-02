#include <thread>
#include <chrono>

#include "GameLoop.h"
#include "../state/GameState.h"
#include "../state/GameConfig.h"
#include "../io/IInput.h"
#include "../io/IRenderer.h"

#include "PlayerDecisionSystem.h"
#include "BotDecisionSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"

class PlayerDecisionSystem;

GameLoop::GameLoop(GameConfig config, std::unique_ptr<IInput> a_input, std::unique_ptr<IRenderer> renderer)
        : m_player_decision_system(std::make_unique<PlayerDecisionSystem>(std::move(a_input)))
        , m_bot_decision_system(std::make_unique<BotDecisionSystem>())
        , m_game_state(std::make_unique<GameState>(config))
        , m_movement_system(std::make_unique<MovementSystem>())
        , m_collision_system(std::make_unique<CollisionSystem>())
        , m_renderer(std::move(renderer))
{
}

GameLoop::~GameLoop() = default;

void GameLoop::run() 
{
    while (true) 
    {
        m_player_decision_system->update(*m_game_state);

        m_bot_decision_system->update(*m_game_state);

        m_movement_system->update(*m_game_state);

        m_renderer->render(*m_game_state);

        m_collision_system->update(*m_game_state);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
