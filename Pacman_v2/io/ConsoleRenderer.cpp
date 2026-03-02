#include <iostream>
#include <vector>
#include <string>

#include "../state/GameState.h"
#include "ConsoleRenderer.h"

void ConsoleRenderer::render(const GameState& state)
{
    const auto& tiles = state.m_map.m_tiles;
    const int height = static_cast<int>(tiles.size());
    const int width = static_cast<int>(tiles[0].size());


    std::vector<std::string> buffer(height, std::string(width, ' '));

    // Draw map
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            buffer[y][x] = tile_to_char(tiles[y][x]);
        }
    }

    // Draw pacman
    buffer[state.m_pacman.m_position.y][state.m_pacman.m_position.x] = 'C';

    // Draw ghosts
    for (const auto& ghost : state.m_ghosts)
    {
        buffer[ghost.m_position.y][ghost.m_position.x] = 'G';
    }

    // Clear console
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
#endif

    // Print 
    for (const auto& line : buffer)
    {
        std::cout << line << '\n';
    }

    std::cout << "Controls: W A S D, q = quit\n";
}