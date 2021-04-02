#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>

SpriteComponent::SpriteComponent():
	srcRect({0,0,32,32})
{
}

SpriteComponent::SpriteComponent(std::string file) :
	texture(TextureManager::load_texture(file)),
	srcRect({ 0,0,32,32 })
{
}

void SpriteComponent::set_texture(std::string file)
{
	texture = TextureManager::load_texture(file);
}

void SpriteComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().get_ptr();
	std::cout << transform.get() << "\n";
	destRect = { transform->x, transform->y, 32, 32 };
}

void SpriteComponent::update()
{
	destRect.x = transform->x;
	destRect.y = transform->y;
}

void SpriteComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);
}
