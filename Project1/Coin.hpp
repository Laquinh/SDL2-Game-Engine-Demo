#pragma once
#ifndef COIN_HPP
#define COIN_HPP

#include "Component.hpp"

class Scene;
struct Rectangle;

class Coin : public Component
{
public:
	Coin& onCollision(Entity& e);
	static Entity& create(Scene& scene, const Rectangle& destRect);
};

#endif