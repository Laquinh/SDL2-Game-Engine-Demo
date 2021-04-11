#ifndef COIN_HPP
#define COIN_HPP

#include "Component.hpp"

class Coin : public Component
{
public:
	Coin& onCollision(Entity& e);
};

#endif