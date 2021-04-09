#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "Game.hpp"
#include "Component.hpp"
#include "ECS.hpp"
#include "VisibleComponent.hpp"

class KeyboardController : public Component
{
public:
	KeyboardController& init() override;
	KeyboardController& handle();
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<VisibleComponent> visible;
};

#endif