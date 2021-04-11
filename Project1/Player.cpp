#include "Player.hpp"
#include "SDL.h"
#include "Game.hpp"
#include "KeyboardController.hpp"

Player& Player::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	visible = entity.lock()->get_component<AnimationComponent>().shared_from_this();

	return *this;
}

Player& Player::handle_events()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			transform->velocity.y = -1;
			visible->play("walk");
			break;
		case SDLK_a:
			transform->velocity.x = -1;
			visible->play("walk");
			break;
		case SDLK_s:
			transform->velocity.y = 1;
			visible->play("walk");
			break;
		case SDLK_d:
			transform->velocity.x = 1;
			visible->play("walk");
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
			visible->play("idle");
			break;
		case SDLK_a:
		case SDLK_d:
			transform->velocity.x = 0;
			visible->play("idle");
			break;
		}
	}
	
    return *this;
}

Entity& Player::create(ComponentManager& manager)
{
	auto& player = manager.add_entity("alien");

	player.add_component<TransformComponent>(SDL_Rect{ 50, 150, 96, 96 });
	player.add_component<AnimationComponent>("assets/alien-anim.png", SDL_Rect{ 0, 0, 24, 24 })
		.add_animation("idle", { 0, 4, 225 })
		.add_animation("walk", { 1, 4, 100 })
		.play("idle");
	player.add_component<KeyboardController>();
	player.add_component<ColliderComponent>();
	player.add_component<Player>();
	player.add_group(1);

	return player;
}
