#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include <map>
#include <memory>
#include <string>

struct TextureManager
{
	static std::shared_ptr<SDL_Texture> load_texture(std::string file);
	static void draw(SDL_Texture&, const SDL_Rect& src, const SDL_Rect& dest);
	static std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
};

#endif