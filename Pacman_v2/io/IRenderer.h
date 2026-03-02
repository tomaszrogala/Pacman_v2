#pragma once

class GameState;

struct IRenderer 
{
    virtual ~IRenderer() = default;
    virtual void render(const GameState& a_state) = 0;
};