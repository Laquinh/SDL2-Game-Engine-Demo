#ifndef MAP_HPP
#define MAP_HPP

#include "destroyers.hpp"

#include <string>
#include <array>

class Scene;
class Entity;

namespace Map
{
	void load_map(Scene& scene, const std::string& file, int sizeX, int sizeY);
	Entity& add_tile(Scene& scene, int row, int column, int id);
}

#endif
