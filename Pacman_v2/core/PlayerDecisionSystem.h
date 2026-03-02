#pragma once
#include <memory>
#include "../io/IInput.h"

struct GameState;

class PlayerDecisionSystem
{
public:
	PlayerDecisionSystem(std::unique_ptr<IInput> a_input);
	void update(GameState& a_state) const;

private:
	std::unique_ptr<IInput> m_input;
};

