#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>

SpriteComponent::SpriteComponent():
	srcRect({0,0,32,32})
{
}

SpriteComponent::SpriteComponent(const std::string& file) :
	texture(TextureManager::load_texture(file)),
	srcRect({ 0,0,16,16 })
{
}

SpriteComponent::SpriteComponent(const std::string& file, int frames, int speed) :
	texture(TextureManager::load_texture(file)),
	srcRect({ 0,0,24,24 }),
	frames(frames),
	speed(speed),
	animated(true)
{
}

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect& srcRect) :
	texture(TextureManager::load_texture(file)),
	srcRect(srcRect)
{
}

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect&, int frames, int speed):
	texture(TextureManager::load_texture(file)),
	srcRect(srcRect),
	frames(frames),
	speed(speed),
	animated(true)
{
}

SpriteComponent& SpriteComponent::set_texture(std::string file)
{
	texture = TextureManager::load_texture(file);

	return *this;
}

SpriteComponent& SpriteComponent::set_srcRect(const SDL_Rect& rect)
{
	srcRect = rect;

	return *this;
}

SpriteComponent& SpriteComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();

	return *this;
}

SpriteComponent& SpriteComponent::update()
{
	if (animated)
	{
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	}
	destRect = transform->rect;

	return *this;
}

SpriteComponent& SpriteComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);

	return *this;
}
