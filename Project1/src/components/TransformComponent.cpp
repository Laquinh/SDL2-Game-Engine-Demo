#include "TransformComponent.hpp"
#include "../interfaces/TimeManager.hpp"
#include "../Game.hpp"
#include "../interfaces/Collision.hpp"
#include "../Entity.hpp"
#include "ColliderComponent.hpp"
#include "../Vector2D.hpp"

TransformComponent::TransformComponent() :
    rect({ 0, 0, 32, 32 })
{
}

TransformComponent::TransformComponent(int x, int y):
    rect({x, y, 32, 32})
{
}

TransformComponent::TransformComponent(const Rectangle& rect) :
    rect(rect.x, rect.y, rect.width, rect.height)
{
}

TransformComponent::~TransformComponent()
{
}

TransformComponent& TransformComponent::set_position(int x, int y)
{
    if (auto p = entity.lock())
    {
        if (p->has_component<ColliderComponent>() && p->get_component<ColliderComponent>()->isRigid)
        {
            for (auto& c : Game::colliders)
            {
                if (c->entity.lock().get() != p.get() && c->isRigid && Collision::AABB(c->collider, Rectangle(x , y , rect.width, rect.height )))
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

TransformComponent& TransformComponent::set_orientation(Orientation orient)
{
    orientation = orient;

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

TransformComponent& TransformComponent::set_rect(const Rectangle& rect)
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
    return Vector2D(rect.x, rect.y);
}

Rectangle TransformComponent::get_rect()
{
    return rect;
}

TransformComponent& TransformComponent::set_scale(float scale)
{
    rect.width *= static_cast<int>(scale/this->scale);
    rect.height *= static_cast<int>(scale/this->scale);
    this->scale = scale;

    return *this;
}