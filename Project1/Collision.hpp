#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SDL.h"
#include "ColliderComponent.hpp"

class Collision
{
public:
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
	static bool AABB(const ColliderComponent& a, const ColliderComponent& b);
};

#endif COLLISION_HPP