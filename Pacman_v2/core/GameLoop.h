#pragma once
#include <memory>

struct GameConfig;
struct GameState;

class IInput;
class IRenderer;
class PlayerDecisionSystem;
class BotDecisionSystem;
class MovementSystem;
class CollisionSystem;

class GameLoop 
{
public:
    GameLoop(GameConfig a_config, std::unique_ptr<IInput> a_input, std::unique_ptr<IRenderer> a_renderer);
    
    ~GameLoop();
    
    void run();

private:
    std::unique_ptr<GameState> m_game_state;
    
    std::unique_ptr<PlayerDecisionSystem> m_player_decision_system;
    std::unique_ptr<BotDecisionSystem> m_bot_decision_system;
    std::unique_ptr<MovementSystem> m_movement_system;
    std::unique_ptr<CollisionSystem> m_collision_system;

    std::unique_ptr<IRenderer> m_renderer;
};
