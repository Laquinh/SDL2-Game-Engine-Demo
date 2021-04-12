#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect& pSrcRect = SDL_Rect{0,0,16,16})
{
	texture = TextureManager::load_texture(file);
	srcRect = pSrcRect;
}

SpriteComponent& SpriteComponent::set_texture(const std::string& file)
{
	texture = TextureManager::load_texture(file);

	return *this;
}

SpriteComponent& SpriteComponent::set_srcRect(const SDL_Rect& rect)
{
	srcRect = rect;

	return *this;
}

SpriteComponent& SpriteComponent::update()
{
	destRect = transform->get_rect();

	return *this;
}
