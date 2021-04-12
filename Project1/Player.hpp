#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Component.hpp"
#include "AnimationComponent.hpp"

class Player : public Component
{
public:
	Player& init() override;
	Player& update() override;
	Player& handle_events(const SDL_Event& event) override;

	static Entity& create(Scene& scene);

	int money = 0;
	int speed = 500;
	Vector2D velocity = { 0, 0 };
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<AnimationComponent> animation;
};

#endif