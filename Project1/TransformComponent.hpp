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
	~TransformComponent() override;

	void init() override;
	void update() override;
	void draw() override;
	void set_position(int, int);
	Vector2D get_position();
	void set_scale(float);

	std::shared_ptr<TransformComponent> get_ptr();

	SDL_Rect rect;
	Vector2D velocity;
	const int speed = 3;
	float scale = 1;
};

#endif