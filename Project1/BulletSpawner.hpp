#ifndef BULLETSPAWNER_HPP
#define BULLETSPAWNER_HPP

#include "Component.hpp"
#include "Entity.hpp"

class BulletSpawner : public Component
{
public:
	BulletSpawner();
	~BulletSpawner();

	BulletSpawner& init() override;

	static Entity& create(Scene& scene);
private:
	std::atomic<bool> destroyed;
	BulletSpawner& spawn_bullet();
};

#endif