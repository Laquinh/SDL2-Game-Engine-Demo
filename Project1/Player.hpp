#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Component.hpp"
#include "AnimationComponent.hpp"

class Player : public Component
{
public:
	Player& init() override;
	Player& handle_events() override;

	static Entity& create(ComponentManager& manager);
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<AnimationComponent> visible;
};

#endif