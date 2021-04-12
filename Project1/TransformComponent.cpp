#include "TransformComponent.hpp"
#include "TimeManager.hpp"
#include "Game.hpp"
#include "Collision.hpp"

TransformComponent::TransformComponent() :
    //position({0, 0})
    rect({ 0, 0, 32, 32 })
{
}

TransformComponent::TransformComponent(int x, int y):
    //position({ static_cast<float>(x), static_cast<float>(y) })
    rect({x, y, 32, 32})
{
}

TransformComponent::TransformComponent(const SDL_Rect& rect) :
    //position({ static_cast<float>(x), static_cast<float>(y) })
    rect(rect)
{
}

TransformComponent::~TransformComponent()
{
}

TransformComponent& TransformComponent::set_position(int x, int y)
{
    if (auto p = entity.lock())
    {
        if (p->has_component<ColliderComponent>() && p->get_component<ColliderComponent>().isRigid)
        {
            for (auto& c : Game::colliders)
            {
                if (c->entity.lock().get() != p.get() && c->isRigid && Collision::AABB(c->collider, { x , y , rect.w, rect.h }))
                {
                    return *this;
                }
            }
        }
        rect.x = x;
        rect.y = y;
    }
    return *this;
}

TransformComponent& TransformComponent::set_x(int x)
{
    set_position(x, rect.y);

    return *this;
}

TransformComponent& TransformComponent::set_y(int y)
{
    set_position(rect.x, y);

    return *this;
}

TransformComponent& TransformComponent::add_x(int x)
{
    set_position(rect.x + x, rect.y);

    return *this;
}

TransformComponent& TransformComponent::add_y(int y)
{
    set_position(rect.x, rect.y + y);

    return *this;
}

int TransformComponent::get_x()
{
    return rect.x;
}

int TransformComponent::get_y()
{
    return rect.y;
}

TransformComponent& TransformComponent::set_rect(const SDL_Rect& rect)
{
    this->rect = rect;

    return *this;
}

TransformComponent& TransformComponent::reset_scale(float s)
{
    scale = s;

    return *this;
}

Vector2D TransformComponent::get_position()
{
    return Vector2D(static_cast<float>(rect.x), static_cast<float>(rect.y));
}

SDL_Rect TransformComponent::get_rect()
{
    return rect;
}

TransformComponent& TransformComponent::set_scale(float scale)
{
    rect.w *= static_cast<int>(scale/this->scale);
    rect.h *= static_cast<int>(scale/this->scale);
    this->scale = scale;

    return *this;
}