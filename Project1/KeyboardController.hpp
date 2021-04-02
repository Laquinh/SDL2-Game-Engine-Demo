#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "Game.hpp"
#include "ECS.hpp"

class KeyboardController : public Component
{
public:
	void init() override;
	void update() override;
private:
	std::shared_ptr<TransformComponent> transform;
};

#endif