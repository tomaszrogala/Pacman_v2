#include <iostream>
#include <vector>
#include <string>

#include "../state/GameState.h"
#include "ConsoleRenderer.h"

void ConsoleRenderer::render(const GameState& a_state)
{
    const auto& tiles = a_state.m_Map.m_Tiles;
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
    buffer[a_state.m_Pacman.m_Position.m_Y][a_state.m_Pacman.m_Position.m_X] = 'C';

    // Draw ghosts
    for (const auto& ghost : a_state.m_Ghosts)
    {
        buffer[ghost.m_Position.m_Y][ghost.m_Position.m_X] = 'G';
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