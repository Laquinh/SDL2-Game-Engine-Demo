#ifndef COLLIDERCOMPONENT_HPP
#define COLLIDERCOMPONENT_HPP

#include "Component.hpp"
#include "ECS.hpp"

struct ColliderComponent : public Component
{
	SDL_Rect collider;
	std::string tag;

	std::shared_ptr<TransformComponent> transform;

	void init() override;
	void update() override;
};

#endif