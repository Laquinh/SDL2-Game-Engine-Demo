#ifndef MAP_HPP
#define MAP_HPP

#include "SDL.h"
#include "destroyers.hpp"

#include <array>

class Map
{
public:
	Map();
	~Map();

	template<size_t cols, size_t rows>
	void load_map(const std::array<std::array<int, cols>, rows>&);

	void draw_map();

private:
	enum Type {
		GRASS,
		DIRT,
		WATER
	};
	SDL_Rect srcRect;
	SDL_Rect destRect;
	
	unique_SDL_Texture grass; 
	unique_SDL_Texture dirt; 
	unique_SDL_Texture water;

	std::array<std::array<int, 25>, 20> map;
};

#endif