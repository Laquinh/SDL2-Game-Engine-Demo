#ifndef VISIBLECOMPONENT_HPP
#define VISIBLECOMPONENT_HPP

#include "SDL.h"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include <string>

class VisibleComponent : public Component
{
public:
	VisibleComponent& init() override;
	VisibleComponent& draw() override;
	virtual VisibleComponent& play(const std::string& str);
protected:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SDL_Texture> texture;
	SDL_Rect srcRect, destRect;
};

#endif