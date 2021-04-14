#ifndef BULLETSPAWNER_HPP
#define BULLETSPAWNER_HPP

#include "Component.hpp"
#include "Entity.hpp"
#include <chrono>

class BulletSpawner : public Component
{
public:
	BulletSpawner();
	~BulletSpawner();

	BulletSpawner& update() override;

	static Entity& create(Scene& scene);
private:
	BulletSpawner& spawn_bullet();
	std::chrono::steady_clock::time_point lastShot;
};

#endif