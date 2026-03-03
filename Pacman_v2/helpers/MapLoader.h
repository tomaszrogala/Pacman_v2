#pragma once

#include "../state/Map.h"
#include "../state/Tile.h"
#include "../utils/Position2D.h"

#include <string>

class MapLoader
{
public:
    static Map load_from_file(const std::string& a_path);
};
