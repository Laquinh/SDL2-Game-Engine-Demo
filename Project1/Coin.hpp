#ifndef COIN_HPP
#define COIN_HPP

#include "SDL.h"
#include "Component.hpp"
#include "Scene.hpp"

class Coin : public Component
{
public:
	Coin& onCollision(Entity& e);
	static Entity& create(Scene& scene, const SDL_Rect& destRect);
};

#endif