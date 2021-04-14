#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include <memory>

#include "SDL.h"
#include "Component.hpp"
#include "Vector2D.hpp"
#include "Rectangle.hpp"

class TransformComponent : public Component, public std::enable_shared_from_this<TransformComponent>
{
	friend class VisibleComponent;
	friend class KeyboardController;
	friend struct ColliderComponent;
public:
	enum Orientation
	{
		NORTH,
		WEST,
		SOUTH,
		EAST
	};

	TransformComponent();
	TransformComponent(int, int);
	TransformComponent(const Rectangle&);
	~TransformComponent();

	TransformComponent& set_position(int, int);
	TransformComponent& set_orientation(Orientation orient);
	TransformComponent& set_x(int x);
	TransformComponent& set_y(int y);
	TransformComponent& add_x(int x);
	TransformComponent& add_y(int y);
	int get_x();
	int get_y();
	TransformComponent& set_rect(const Rectangle&);
	TransformComponent& reset_scale(float s = 1);
	Vector2D get_position();
	Rectangle get_rect();
	TransformComponent& set_scale(float);

private:
	Rectangle rect;
	float scale = 1;
	Orientation orientation = NORTH;
};

#endif