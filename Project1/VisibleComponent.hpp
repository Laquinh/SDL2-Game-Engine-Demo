#ifndef VISIBLECOMPONENT_HPP
#define VISIBLECOMPONENT_HPP

#include "Component.hpp"
#include "TransformComponent.hpp"
#include <string>

struct SDL_Texture;

class VisibleComponent : public Component
{
public:
	VisibleComponent& init() override;
	VisibleComponent& draw() override;
	virtual VisibleComponent& play(const std::string& str);
protected:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SDL_Texture> texture;
	Rectangle srcRect, destRect;
	TransformComponent::Orientation orientation;
};

#endif