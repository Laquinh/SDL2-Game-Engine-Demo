#ifndef COLLISION_HPP
#define COLLISION_HPP

struct Rectangle;
class ColliderComponent;

namespace Collision
{
	int AABB(const Rectangle& a, const Rectangle& b);
	int AABB(const ColliderComponent& a, const ColliderComponent& b);
}

#endif COLLISION_HPP