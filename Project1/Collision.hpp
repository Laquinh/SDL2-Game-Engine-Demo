#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SDL.h"

class Collision
{
public:
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
};

#endif COLLISION_HPP