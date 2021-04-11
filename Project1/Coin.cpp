#include "Coin.hpp"
#include "TransformComponent.hpp"

Coin& Coin::onCollision(Entity& e)
{
    if (e.tag == "alien")
    {
        entity.lock()->destroy();
    }

    return *this;
}