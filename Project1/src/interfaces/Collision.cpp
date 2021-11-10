#include "Collision.hpp"
#include "../Rectangle.hpp"
#include "../components/ColliderComponent.hpp"

namespace Collision
{
    int AABB(const Rectangle& a, const Rectangle& b)
    {
        return (a.x + a.width > b.x &&
                b.x + b.width > a.x &&
                a.y + a.height > b.y &&
                b.y + b.height > a.y);
    }

    int AABB(const ColliderComponent& a, const ColliderComponent& b)
    {
        return AABB(a.collider, b.collider);
    }
}