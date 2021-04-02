#include "KeyboardController.hpp"

KeyboardController& KeyboardController::init()
{
	transform = entity.lock()->get_component<TransformComponent>().get_ptr();

	return *this;
}

KeyboardController& KeyboardController::update()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			transform->velocity.y = -1;
			break;
		case SDLK_a:
			transform->velocity.x = -1;
			break;
		case SDLK_s:
			transform->velocity.y = 1;
			break;
		case SDLK_d:
			transform->velocity.x = 1;
			break;
		}
	}
	else if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_s:
			transform->velocity.y = 0;
			break;
		case SDLK_a:
		case SDLK_d:
			transform->velocity.x = 0;
			break;
		}
	}

	return *this;
}
