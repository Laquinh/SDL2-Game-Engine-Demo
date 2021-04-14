#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Component.hpp"
#include "AnimationComponent.hpp"
#include <thread>
#include <mutex>
#include <algorithm>

class Player : public Component
{
public:
	Player& init() override;
	Player& update() override;
	Player& handle_events(const SDL_Event& event) override;
	Player& spawn_bullets();

	static Entity& create(Scene& scene);

	int money = 0;
	int speed = 500;
	Vector2D velocity = { 0, 0 };
private:
	std::mutex m;
	std::chrono::steady_clock::time_point startTime;
	bool b = true;

	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<AnimationComponent> animation;
};

#endif