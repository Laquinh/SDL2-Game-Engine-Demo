#include "Player.hpp"
#include "SDL.h"
#include "KeyboardController.hpp"
#include "Coin.hpp"
#include "TimeManager.hpp"
#include "Bullet.hpp"

Player& Player::init()
{
	transform = entity.lock()->get_component<TransformComponent>();
	animation = entity.lock()->get_component<AnimationComponent>();

	speed = 350;
	startTime = std::chrono::steady_clock::now();

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
		case SDLK_LSHIFT:
			if (money > 0)
			{
				Coin::create(*entity.lock()->scene.lock(), Rectangle( transform->get_x() + 150, transform->get_y(), 32, 32 ));
				--money;
			}
			b = true;
			break;
		case SDLK_SPACE:
			//std::cout << std::chrono::steady_clock::now() >= startTime + std::chrono::seconds(5);
			if (std::chrono::steady_clock::now() >= startTime + std::chrono::seconds(5))
			{
				std::thread t(&Player::spawn_bullets, this);
				t.detach();
			}
			break;
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

Player& Player::spawn_bullets()
{
	using namespace std;
	using namespace std::chrono;
	std::cout << std::hex << this_thread::get_id() << '\n';
	if (m.try_lock())
	{
		startTime = std::chrono::steady_clock::now();
		while (auto p = entity.lock()->scene.lock())
		{
			Bullet::create(*entity.lock()->scene.lock(), Rectangle(transform->get_x() + 150, transform->get_y(), 32, 32));
			this_thread::sleep_for(milliseconds(100));

			if (steady_clock::now() >= startTime + seconds(1))
			{
				break;
			}
		}
		m.unlock();
	}
	return *this;
}

Entity& Player::create(Scene& scene)
{
	auto& player = scene.add_entity("player");

	player.add_component<TransformComponent>(Rectangle( 50, 150, 96, 96 ));
	player.add_component<AnimationComponent>("assets/alien-anim.png", Rectangle(0, 0, 24, 24))
		->add_animation("idle", { 0, 4, 225 })
		.add_animation("walk", { 1, 4, 100 })
		.play("idle");
	player.add_component<KeyboardController>();
	player.add_component<ColliderComponent>()
		->isRigid = true;
	player.add_component<Player>();
	player.add_group(1);

	return player;
}
