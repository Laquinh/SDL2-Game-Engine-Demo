#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include <memory>

#include "SDL.h"
#include "Component.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component, public std::enable_shared_from_this<TransformComponent>
{
	friend class VisibleComponent;
	friend class KeyboardController;
	friend struct ColliderComponent;
public:
	TransformComponent();
	TransformComponent(int, int);
	TransformComponent(const SDL_Rect&);
	~TransformComponent();

	TransformComponent& set_position(int, int);
	TransformComponent& set_x(int x);
	TransformComponent& set_y(int y);
	TransformComponent& add_x(int x);
	TransformComponent& add_y(int y);
	int get_x();
	int get_y();
	TransformComponent& set_rect(const SDL_Rect&);
	TransformComponent& reset_scale(float s = 1);
	Vector2D get_position();
	SDL_Rect get_rect();
	TransformComponent& set_scale(float);

private:
	SDL_Rect rect;
	float scale = 1;
};

#endif