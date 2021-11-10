#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "SDL_ttf.h"
#include "../destroyers.hpp"
#include "../components/TransformComponent.hpp"

#include <map>
#include <memory>
#include <string>

class CameraComponent;
struct Rectangle;

namespace AssetManager
{
	void init(const std::shared_ptr<CameraComponent>& pCamera);
	void draw(SDL_Texture&, const Rectangle& src, Rectangle dest, double angle);
	void draw(SDL_Texture&, Rectangle dest, double angle);

	std::shared_ptr<SDL_Texture> load_texture(std::string file);
	std::shared_ptr<TTF_Font> load_font(std::string file, int fontSize);

	inline std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
	inline std::map<std::string, std::shared_ptr<TTF_Font>> fonts;
	inline std::shared_ptr<CameraComponent> camera;
}

#endif