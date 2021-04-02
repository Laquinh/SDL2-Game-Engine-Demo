#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "ComponentManager.hpp"
#include "Vector2D.hpp"

struct TransformComponent : public Component, public std::enable_shared_from_this<TransformComponent>
{
	Vector2D position;

	TransformComponent();
	TransformComponent(int, int);
	~TransformComponent() override;

	void init() override;
	void update() override;
	void draw() override;
	void set_position(int, int);

	std::shared_ptr<TransformComponent> get_ptr();
};

#endif