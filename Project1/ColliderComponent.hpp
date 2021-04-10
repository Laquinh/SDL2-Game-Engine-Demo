#ifndef COLLIDERCOMPONENT_HPP
#define COLLIDERCOMPONENT_HPP

#include "Component.hpp"
#include "TransformComponent.hpp"

#include <iostream>
#include <memory>

struct ColliderComponent : public Component, public std::enable_shared_from_this<ColliderComponent>
{
	SDL_Rect collider;

	std::shared_ptr<TransformComponent> transform;

	ColliderComponent();
	~ColliderComponent();

	ColliderComponent& init() override;
	ColliderComponent& update() override;
	ColliderComponent& destroy() override;

	bool isRigid = false;
};

#endif