#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "Component.hpp"

class Entity;
class TransformComponent;
class VisibleComponent;
union SDL_Event;

class KeyboardController : public Component
{
public:
	KeyboardController& init() override;
	KeyboardController& handle_events(const SDL_Event& event) override;
private:
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<VisibleComponent> visible;
};

#endif