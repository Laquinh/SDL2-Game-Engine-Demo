#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "Game.hpp"
#include "Component.hpp"
#include "ECS.hpp"

class KeyboardController : public Component
{
public:
	KeyboardController& init() override;
	KeyboardController& update() override;
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SpriteComponent> sprite;
};

#endif