#include "PlayerDecisionSystem.h"
#include "../state/GameState.h"

PlayerDecisionSystem::PlayerDecisionSystem(std::unique_ptr<IInput> a_input) 
	: m_input(std::move(a_input))
{
}

void PlayerDecisionSystem::update(GameState& a_state) const
{
    a_state.m_Pacman.m_Direction = m_input->read_direction();
}
