#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include <memory>

#include "SDL.h"
#include "Component.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component, public std::enable_shared_from_this<TransformComponent>
{
	friend class SpriteComponent;
	friend class KeyboardController;
	friend struct ColliderComponent;
public:
	TransformComponent();
	TransformComponent(int, int);
	TransformComponent(const SDL_Rect&);
	~TransformComponent();

	TransformComponent& update() override;
	TransformComponent& set_position(int, int);
	TransformComponent& set_rect(const SDL_Rect&);
	TransformComponent& reset_scale(float s = 1);
	Vector2D get_position();
	SDL_Rect get_rect();
	TransformComponent& set_scale(float);

	SDL_Rect rect;
	Vector2D velocity;
	const int speed = 3;
	float scale = 1;
};

#endif