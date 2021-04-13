#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SDL.h"
#include "ColliderComponent.hpp"

class Collision
{
public:
	static int AABB(const Rectangle& a, const Rectangle& b);
	static int AABB(const ColliderComponent& a, const ColliderComponent& b);
};

#endif COLLISION_HPP