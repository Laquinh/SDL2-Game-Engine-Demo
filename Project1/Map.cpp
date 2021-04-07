#include "Map.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

#include <fstream>
#include <array>

Map::Map()
{
}

Map::~Map()
{
}

void Map::load_map(const std::string& file, int rows, int columns)
{
	int tile;
	std::fstream mapFile(file, std::ios_base::in);

	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; ++c)
		{
			mapFile >> tile;
			Game::add_tile(r, c, tile);
			mapFile.ignore();
		}
	}
}