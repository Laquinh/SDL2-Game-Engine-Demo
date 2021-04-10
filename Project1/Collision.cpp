#include "Collision.hpp"

int Collision::AABB(const SDL_Rect& a, const SDL_Rect& b)
{
    /*if (a.x + a.w > b.x)
    {
        return 1;
    }
    if(b.x + b.w > a.x)
    {
        return 2;
    }
    if (a.y + a.h > b.y)
    {
        return 3;
    }
    if (b.y + b.h > a.y)
    {
        return 4;
    }*/

    if (a.x + a.w > b.x &&
        b.x + b.w > a.x &&
        a.y + a.h > b.y &&
        b.y + b.h > a.y)
    {
        return true;
    }
    else
    {
        return 0;
    }
}

int Collision::AABB(const ColliderComponent& a, const ColliderComponent& b)
{
    return AABB(a.collider, b.collider);
}