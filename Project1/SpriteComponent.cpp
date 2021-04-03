#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>

SpriteComponent::SpriteComponent():
	srcRect({0,0,32,32})
{
}

SpriteComponent::SpriteComponent(const std::string& file) :
	texture(TextureManager::load_texture(file)),
	srcRect({ 0,0,32,32 })
{
}

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect& srcRect) :
	texture(TextureManager::load_texture(file)),
	srcRect(srcRect)
{
}

SpriteComponent& SpriteComponent::set_texture(std::string file)
{
	texture = TextureManager::load_texture(file);

	return *this;
}

SpriteComponent& SpriteComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	std::cout << transform.get() << "\n";

	return *this;
}

SpriteComponent& SpriteComponent::update()
{
	destRect = transform->rect;

	return *this;
}

SpriteComponent& SpriteComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);

	return *this;
}
