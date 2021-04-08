#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <iostream>

#include "destroyers.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"

class SpriteComponent : public Component, public std::enable_shared_from_this<SpriteComponent>
{
public:
	SpriteComponent();
	SpriteComponent(const std::string&);
	SpriteComponent(const std::string&, int frames, int speed);
	SpriteComponent(const std::string&, const SDL_Rect&);
	SpriteComponent(const std::string&, const SDL_Rect&, int frames, int speed);

	SpriteComponent& set_texture(std::string);
	SpriteComponent& set_srcRect(const SDL_Rect& rect);

	SpriteComponent& init() override;
	SpriteComponent& update() override;
	SpriteComponent& draw() override;
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SDL_Texture> texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 4;
	int speed = 100;
};

#endif