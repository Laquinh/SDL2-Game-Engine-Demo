#include "Player.hpp"
#include "SDL.h"
#include "KeyboardController.hpp"
#include "Coin.hpp"
#include "TimeManager.hpp"
#include "Bullet.hpp"
#include "Scene.hpp"
#include "AnimationComponent.hpp"
#include "SDL.h"
#include "Entity.hpp"
#include "ColliderComponent.hpp"
#include "BulletSpawner.hpp"

Player::Player() :
	velocity({ 0, 0 })
{
}

Player& Player::init()
{
	transform = entity.lock()->get_component<TransformComponent>();
	animation = entity.lock()->get_component<AnimationComponent>();

	speed = 64*5;

	animation->play("idle");

	return *this;
}

Player& Player::update()
{
	const uint8_t* keyStates = SDL_GetKeyboardState(NULL);

	if (keyStates[SDL_SCANCODE_W])
	{
		velocity.y = -1;
		velocity.x = 0;
		animation->play("walk");
	}
	else if (keyStates[SDL_SCANCODE_S])
	{
		velocity.y = 1;
		velocity.x = 0;
		animation->play("walk");
	}
	
	else if (keyStates[SDL_SCANCODE_A])
	{
		velocity.y = 0;
		velocity.x = -1;
		animation->play("walk");
	}
	else if (keyStates[SDL_SCANCODE_D])
	{
		velocity.y = 0;
		velocity.x = 1;
		animation->play("walk");
	}
	else
	{
		velocity.x = 0;
		velocity.y = 0;
		animation->play("idle");
	}

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
		case SDLK_LSHIFT:
			if (money > 0)
			{
				Coin::create(*entity.lock()->scene.lock(), Rectangle(transform->get_x() + 150, transform->get_y(), 32, 32));
				--money;
			}
			break;
		case SDLK_SPACE:
			if (auto p = entity.lock()->scene.lock()->get_entity_with_tag("spawner")) p->destroy();
			break;
		case SDLK_RSHIFT:
			auto& s = BulletSpawner::create(*entity.lock()->scene.lock());
			break;
		}
	}
    return *this;
}

Entity& Player::create(Scene& scene)
{
	auto& player = scene.add_entity("player");

	player.add_component<TransformComponent>(Rectangle( 50, 150, 96, 96 ));
	player.add_component<AnimationComponent>("assets/brendan-anim.png", Rectangle(0, 0, 24, 24))
		->add_animation("idle", { 0, 4, 225 })
		.add_animation("walk", { 1, 4, 220 })
		.play("idle");
	player.add_component<KeyboardController>();
	player.add_component<ColliderComponent>()
		->isRigid = true;
	player.add_component<Player>();
	player.add_group(1);

	return player;
}
