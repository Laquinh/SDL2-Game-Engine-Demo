#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include <iostream>
#include <memory>

class TextureManager
{
public:
	static unique_SDL_Texture load_texture(const std::string& file);
	static void draw(SDL_Texture&, const SDL_Rect& src, const SDL_Rect& dest);
};

#endif