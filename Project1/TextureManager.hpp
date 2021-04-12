#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include "CameraComponent.hpp"
#include <map>
#include <memory>
#include <string>

namespace TextureManager
{
	void init(const std::shared_ptr<CameraComponent>& pCamera);
	std::shared_ptr<SDL_Texture> load_texture(std::string file);
	void draw(SDL_Texture&, const SDL_Rect& src, const SDL_Rect& dest);

	inline std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
	inline std::shared_ptr<CameraComponent> camera;
}

#endif