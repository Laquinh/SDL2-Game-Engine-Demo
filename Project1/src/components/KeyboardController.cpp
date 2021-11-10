#include "KeyboardController.hpp"
#include "AnimationComponent.hpp"
#include "Coin.hpp"
#include "../Game.hpp"
#include "../Entity.hpp"
#include "TransformComponent.hpp"
#include "VisibleComponent.hpp"

KeyboardController& KeyboardController::init()
{
	transform = entity.lock()->get_component<TransformComponent>();
	visible = entity.lock()->get_component<AnimationComponent>();
	return *this;
}

KeyboardController& KeyboardController::handle_events(const SDL_Event& event)
{
	if (event.type == SDL_QUIT)
	{
		Game::isRunning = false;
	}
	return *this;
}
