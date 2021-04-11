#ifndef COIN_HPP
#define COIN_HPP

#include "SDL.h"
#include "Component.hpp"
#include "ComponentManager.hpp"

class Coin : public Component
{
public:
	Coin& onCollision(Entity& e);
	static Entity& create(ComponentManager& manager, const SDL_Rect& destRect);
};

#endif