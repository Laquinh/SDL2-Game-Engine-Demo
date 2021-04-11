#include "KeyboardController.hpp"
#include "AnimationComponent.hpp"
#include "Coin.hpp"
#include "Game.hpp"

KeyboardController& KeyboardController::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	visible = entity.lock()->get_component<AnimationComponent>().shared_from_this();
	return *this;
}

KeyboardController& KeyboardController::handle_events()
{
	if (Game::event.type == SDL_QUIT)
	{
		Game::isRunning = false;
	}
	return *this;
}
