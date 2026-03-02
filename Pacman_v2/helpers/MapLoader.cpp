#include "MapLoader.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <stdexcept>
#include <vector>

Map MapLoader::load_from_file(const std::string& path)
{
    std::ifstream file(path);
    if (!file)
        throw std::runtime_error("MapLoader: cannot open file: " + path);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line))
    {
        // Windows CRLF -> remove '\r'
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        lines.push_back(line);
    }

    if (lines.empty())
        throw std::runtime_error("MapLoader: map file is empty: " + path);

    // Rectangular validation
    const std::size_t width = lines[0].size();
    if (width == 0)
        throw std::runtime_error("MapLoader: first line has zero width: " + path);

    for (std::size_t y = 0; y < lines.size(); ++y)
    {
        if (lines[y].size() != width)
        {
            throw std::runtime_error(
                "MapLoader: non-rectangular map. Line " + std::to_string(y) +
                " has width " + std::to_string(lines[y].size()) +
                ", expected " + std::to_string(width));
        }
    }

    Map map;
    map.m_tiles.resize(lines.size(), std::vector<Tile>(width, Tile::Empty));

    for (std::size_t y = 0; y < lines.size(); ++y)
    {
        for (std::size_t x = 0; x < width; ++x)
        {
            map.m_tiles[y][x] = tile_from_char(lines[y][x]);
        }
    }

    return map;
}
