#include "SpriteComponent.hpp"
#include "../interfaces/AssetManager.hpp"
#include <iostream>

SpriteComponent::SpriteComponent(const std::string& file, const Rectangle& srcRect = Rectangle(0,0,16,16))
{
	texture = AssetManager::load_texture(file);
	this->srcRect = srcRect;
}

SpriteComponent& SpriteComponent::set_texture(const std::string& file)
{
	texture = AssetManager::load_texture(file);

	return *this;
}

SpriteComponent& SpriteComponent::set_srcRect(const Rectangle& rect)
{
	srcRect = rect;

	return *this;
}

SpriteComponent& SpriteComponent::update()
{
	destRect = transform->get_rect();

	return *this;
}
