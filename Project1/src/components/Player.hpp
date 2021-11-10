#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Component.hpp"
#include "../Vector2D.hpp"

class Scene;
class TransformComponent;
class AnimationComponent;
union SDL_Event;

class Player : public Component
{
public:
	Player();
	Player& init() override;
	Player& update() override;
	Player& handle_events(const SDL_Event& event) override;
	//Player& spawn_bullets();

	static Entity& create(Scene& scene);

	int money = 0;
	int speed = 500;
	Vector2D velocity;
private:
	/*std::mutex m;
	std::chrono::steady_clock::time_point startTime;
	bool b = true;*/

	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<AnimationComponent> animation;
};

#endif