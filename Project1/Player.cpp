#include "Player.hpp"
#include "SDL.h"
#include "KeyboardController.hpp"
#include "Coin.hpp"

Player& Player::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	animation = entity.lock()->get_component<AnimationComponent>().shared_from_this();

	return *this;
}

Player& Player::handle_events(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			transform->velocity.y = -1;
			animation->play("walk");
			break;
		case SDLK_a:
			transform->velocity.x = -1;
			animation->play("walk");
			break;
		case SDLK_s:
			transform->velocity.y = 1;
			animation->play("walk");
			break;
		case SDLK_d:
			transform->velocity.x = 1;
			animation->play("walk");
			break;
		case SDLK_SPACE:
			if (money > 0)
			{
				Coin::create(*entity.lock()->manager.lock(), SDL_Rect{ transform->rect.x + 100, transform->rect.y, 32, 32 });
				--money;
			}
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_s:
			transform->velocity.y = 0;
			animation->play("idle");
			break;
		case SDLK_a:
		case SDLK_d:
			transform->velocity.x = 0;
			animation->play("idle");
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
