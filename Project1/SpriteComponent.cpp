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

SpriteComponent::SpriteComponent(const std::string& file, bool animated) :
	texture(TextureManager::load_texture(file)),
	srcRect({ 0,0,16,16 }),
	animated(animated)
{
	if (animated)
	{
		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		play("Idle");
	}
}

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect& srcRect) :
	texture(TextureManager::load_texture(file)),
	srcRect(srcRect)
{
}

SpriteComponent::SpriteComponent(const std::string& file, const SDL_Rect& srcRect, bool animated):
	texture(TextureManager::load_texture(file)),
	srcRect(srcRect),
	animated(animated)
{
	Animation idle = Animation(0, 4, 225);
	Animation walk = Animation(1, 4, 100);

	animations.emplace("Idle", idle);
	animations.emplace("Walk", walk);

	play("Idle");
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
		srcRect.y = animIndex * srcRect.h;
	}

	destRect = transform->rect;

	return *this;
}

SpriteComponent& SpriteComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);

	return *this;
}

SpriteComponent& SpriteComponent::play(const std::string str)
{
	frames = animations[str].frames;
	animIndex = animations[str].index;
	speed = animations[str].speed;

	return *this;
}
