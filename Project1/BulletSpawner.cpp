#include "BulletSpawner.hpp"
#include <thread>
#include "Bullet.hpp"
#include "SpriteComponent.hpp"
#include "ColliderComponent.hpp"

BulletSpawner::BulletSpawner():
	destroyed(false)
{
}

BulletSpawner::~BulletSpawner()
{
	destroyed = true;
}

BulletSpawner& BulletSpawner::init()
{
	std::thread t(&BulletSpawner::spawn_bullet, this);
	t.detach();

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
	while (!destroyed)
	{
		if (auto p = entity.lock())
		{
			if (auto s = p->scene.lock())
			{
				Bullet::create(*s, Rectangle(34, 345, 32, 32), TransformComponent::Orientation::WEST);
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}

	return *this;
}
