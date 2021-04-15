#ifndef COLLIDERCOMPONENT_HPP
#define COLLIDERCOMPONENT_HPP

#include "Component.hpp"
#include "Rectangle.hpp"
#include <iostream>
#include <memory>

class TransformComponent;

class ColliderComponent : public Component, public std::enable_shared_from_this<ColliderComponent>
{
public:
	Rectangle collider;

	std::shared_ptr<TransformComponent> transform;

	ColliderComponent();
	~ColliderComponent();

	ColliderComponent& init() override;
	ColliderComponent& update() override;
	ColliderComponent& destroy() override;

	bool isRigid = false;
};

#endif