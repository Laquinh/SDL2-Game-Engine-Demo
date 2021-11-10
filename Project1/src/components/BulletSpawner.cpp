#include "BulletSpawner.hpp"
#include <thread>
#include "Bullet.hpp"
#include "SpriteComponent.hpp"
#include "ColliderComponent.hpp"
#include "../Entity.hpp"
#include "../Scene.hpp"

BulletSpawner::BulletSpawner()
{
	lastShot = std::chrono::steady_clock::now();
}

BulletSpawner::~BulletSpawner()
{
}

BulletSpawner& BulletSpawner::update()
{
	if (std::chrono::steady_clock::now() >= lastShot + std::chrono::seconds(1))
	{
		spawn_bullet();
	}
	return *this;
}

Entity& BulletSpawner::create(Scene& scene)
{
	auto& spawner = scene.add_entity("spawner");

	spawner.add_component<TransformComponent>(Rectangle(0, 300, 64, 64));
	spawner.add_component<SpriteComponent>("assets/spawner.png", Rectangle(0, 0, 16, 16));
	spawner.add_component<ColliderComponent>()
		->isRigid = true;
	spawner.add_component<BulletSpawner>();
	spawner.add_group(0);

	return spawner;
}

BulletSpawner& BulletSpawner::spawn_bullet()
{
	if (auto p = entity.lock())
	{
		if (auto s = p->scene.lock())
		{
			Bullet::create(*s, Rectangle(0, 345, 64, 64), TransformComponent::Orientation::NORTH);
		}
	}
	lastShot = std::chrono::steady_clock::now();
	
	return *this;
}
