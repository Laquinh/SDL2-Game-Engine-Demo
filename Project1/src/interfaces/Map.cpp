#include "Map.hpp"
#include "AssetManager.hpp"
#include "Game.hpp"
#include "Entity.hpp"
#include "TileComponent.hpp"
#include "Scene.hpp"

#include <fstream>
#include <array>

namespace Map
{
	void load_map(Scene& scene, const std::string& file, int rows, int columns)
	{
		int tile;
		std::fstream mapFile(file, std::ios_base::in);

		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < columns; ++c)
			{
				mapFile >> tile;
				add_tile(scene, r, c, tile);
				mapFile.ignore();
			}
		}
	}

	Entity& add_tile(Scene& scene, int row, int column, int id)
	{
		auto& tile(scene.add_entity());
		tile.add_component<TileComponent>(row, column, 64, 64, id);
		tile.add_group(0);

		return tile;
	}
}