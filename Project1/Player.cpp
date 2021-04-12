#include "Player.hpp"
#include "SDL.h"
#include "KeyboardController.hpp"
#include "Coin.hpp"
#include "TimeManager.hpp"

Player& Player::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	animation = entity.lock()->get_component<AnimationComponent>().shared_from_this();

	speed = 350;

	return *this;
}

Player& Player::update()
{
	transform->add_x(speed * TimeManager::get_deltaTime() * velocity.x);
	transform->add_y(speed * TimeManager::get_deltaTime() * velocity.y);

	return *this;
}

Player& Player::handle_events(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			velocity.y = -1;
			animation->play("walk");
			break;
		case SDLK_a:
			velocity.x = -1;
			animation->play("walk");
			break;
		case SDLK_s:
			velocity.y = 1;
			animation->play("walk");
			break;
		case SDLK_d:
			velocity.x = 1;
			animation->play("walk");
			break;
		case SDLK_SPACE:
			if (money > 0)
			{
				Coin::create(*entity.lock()->scene.lock(), SDL_Rect{ transform->get_x() + 100, transform->get_y(), 32, 32 });
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
			velocity.y = 0;
			animation->play("idle");
			break;
		case SDLK_a:
		case SDLK_d:
			velocity.x = 0;
			animation->play("idle");
			break;
		}
	}
    return *this;
}

Entity& Player::create(Scene& scene)
{
	auto& player = scene.add_entity("alien");

	player.add_component<TransformComponent>(SDL_Rect{ 50, 150, 96, 96 });
	player.add_component<AnimationComponent>("assets/alien-anim.png", SDL_Rect{ 0, 0, 24, 24 })
		.add_animation("idle", { 0, 4, 225 })
		.add_animation("walk", { 1, 4, 100 })
		.play("idle");
	player.add_component<KeyboardController>();
	player.add_component<ColliderComponent>()
		.isRigid = true;
	player.add_component<Player>();
	player.add_group(1);

	return player;
}
