#include "SpriteComponent.hpp"
#include "TextureManager.hpp"

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
	position = entity.lock()->get_component<PositionComponent>().get_ptr();
	std::cout << position.get() << "\n";
	destRect = { position->get_x(), position->get_y(), 32, 32 };
}

void SpriteComponent::update()
{
	destRect.x = position->get_x();
	destRect.y = position->get_y();
}

void SpriteComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);
}
