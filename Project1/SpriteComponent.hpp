#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <iostream>
#include <map>

#include "destroyers.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "Animation.hpp"

class SpriteComponent : public Component, public std::enable_shared_from_this<SpriteComponent>
{
public:
	SpriteComponent();
	SpriteComponent(const std::string&);
	SpriteComponent(const std::string&, bool animated);
	SpriteComponent(const std::string&, const SDL_Rect&);
	SpriteComponent(const std::string&, const SDL_Rect&, bool animated);

	SpriteComponent& set_texture(std::string);
	SpriteComponent& set_srcRect(const SDL_Rect& rect);

	SpriteComponent& init() override;
	SpriteComponent& update() override;
	SpriteComponent& draw() override;
	SpriteComponent& play(const std::string str);
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SDL_Texture> texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 4;
	int speed = 100;

	int animIndex = 0;

	std::map<const std::string, Animation> animations;
};

#endif