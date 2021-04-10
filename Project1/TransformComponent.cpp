#include "TransformComponent.hpp"
#include "TimeManager.hpp"

TransformComponent::TransformComponent() :
    //position({0, 0})
    rect({ 0, 0, 32, 32 }),
    velocity({ 0, 0 })
{
}

TransformComponent::TransformComponent(int x, int y):
    //position({ static_cast<float>(x), static_cast<float>(y) })
    rect({x, y, 32, 32}),
    velocity({ 0, 0 })
{
}

TransformComponent::TransformComponent(const SDL_Rect& rect) :
    //position({ static_cast<float>(x), static_cast<float>(y) })
    rect(rect),
    velocity({ 0, 0 })
{
}

TransformComponent::~TransformComponent()
{
}

TransformComponent& TransformComponent::update()
{
    Vector2D product = (velocity * (speed * TimeManager::get_deltaTime()));

    rect.x += round(product.x);
    rect.y += round(product.y);

    return *this;
}

TransformComponent& TransformComponent::set_position(int x, int y)
{
    rect.x = x;
    rect.y = y;

    return *this;
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