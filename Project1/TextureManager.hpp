#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include <iostream>
#include <memory>

class TextureManager
{
public:
	static unique_SDL_Texture load_texture(std::string file, SDL_Renderer& renderer);
};

#endif