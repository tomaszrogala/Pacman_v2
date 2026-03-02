#include "core/GameLoop.h"
#include "state/GameConfig.h"
#include "io/ConsoleInput.h"
#include "io/ConsoleRenderer.h"

int main() 
{
    GameConfig config{ "..\\default_map.txt" };

    auto input = std::make_unique<ConsoleInputAsync>();
    auto renderer = std::make_unique<ConsoleRenderer>();

    GameLoop game(config, std::move(input), std::move(renderer));
    game.run();

    return 0;
}