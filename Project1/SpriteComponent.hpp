#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <iostream>

#include "destroyers.hpp"
#include "ComponentManager.hpp"
#include "TransformComponent.hpp"

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(std::string);

	void set_texture(std::string);

	void init() override;
	void update() override;
	void draw() override;
private:
	std::shared_ptr<TransformComponent> transform;
	unique_SDL_Texture texture;
	SDL_Rect srcRect, destRect;
};

#endif