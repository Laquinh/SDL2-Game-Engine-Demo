#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include "TransformComponent.hpp"

#include <map>
#include <memory>
#include <string>

class CameraComponent;
class Rectangle;

namespace AssetManager
{
	void init(const std::shared_ptr<CameraComponent>& pCamera);
	std::shared_ptr<SDL_Texture> load_texture(std::string file);
	void draw(SDL_Texture&, const Rectangle& src, Rectangle dest, TransformComponent::Orientation orientation);

	inline std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
	inline std::shared_ptr<CameraComponent> camera;
}

#endif