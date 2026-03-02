#pragma once
#include "IRenderer.h"

struct GameState;

class ConsoleRenderer : public IRenderer 
{
public:
    void render(const GameState& a_state) override;
};