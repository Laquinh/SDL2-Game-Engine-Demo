#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <iostream>
#include <map>

#include "VisibleComponent.hpp"

class SpriteComponent : public VisibleComponent, public std::enable_shared_from_this<SpriteComponent>
{
public:
	SpriteComponent() = default;
	SpriteComponent(const std::string&, const SDL_Rect&);

	SpriteComponent& set_texture(const std::string&);
	SpriteComponent& set_srcRect(const SDL_Rect& rect);

	SpriteComponent& update() override;
};

#endif