#include "Bullet.hpp"
#include "TimeManager.hpp"
#include "AnimationComponent.hpp"
#include "ColliderComponent.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Scene.hpp"
#include "Rectangle.hpp"

Bullet::Bullet() :
	speed(600)
{
}

Bullet& Bullet::init()
{
	transform = entity.lock()->get_component<TransformComponent>();
	player = Game::scene->get_entity_with_tag("player")->get_component<Player>();

	speed = 600;

	return *this;
}

Bullet& Bullet::update()
{
	if (transform->get_y() < 1300)
	{
		transform->add_y(speed * TimeManager::get_deltaTime());
	}
	else
	{
		if (auto p = entity.lock())
		{
			p->destroy();
		}
	}

	return *this;
}

Bullet& Bullet::onCollision(Entity& e)
{
	if (e.tag == "coin")
	{
		if (auto p = player.lock()) ++p->money;
		e.destroy();
	}

	return *this;
}

Entity& Bullet::create(Scene& scene, const Rectangle& destRect, TransformComponent::Orientation orientation)
{
	auto& bullet = scene.add_entity("bullet");
	bullet.add_component<TransformComponent>(destRect)
		->set_orientation(orientation);
	bullet.add_component<AnimationComponent>("assets/fireball-anim.png", Rectangle( 0, 0, 16, 16 ))
		->add_animation("move", { 0, 4, 175 })
		.play("move");
	bullet.add_component<ColliderComponent>();
	bullet.add_component<Bullet>();
	bullet.add_group(0);

	return bullet;
}
