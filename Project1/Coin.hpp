#ifndef COIN_HPP
#define COIN_HPP

#include "SDL.h"
#include "Component.hpp"
#include "Scene.hpp"
#include "Rectangle.hpp"

class Coin : public Component
{
public:
	Coin& onCollision(Entity& e);
	static Entity& create(Scene& scene, const Rectangle& destRect);
};

#endif