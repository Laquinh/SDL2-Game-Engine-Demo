#include "TransformComponent.hpp"

TransformComponent::TransformComponent() :
    //position({0, 0})
    rect({ 0, 0, 32, 32 }),
    velocity({ 0, 0 })
{
    std::cout << this << "\n";
    std::cout << "TransformComponent constructed\n";
}

TransformComponent::TransformComponent(int x, int y):
    //position({ static_cast<float>(x), static_cast<float>(y) })
    rect({x, y, 32, 32}),
    velocity({ 0, 0 })
{
    std::cout << this << "\n";
    std::cout << "TransformComponent constructed\n";
}

TransformComponent::~TransformComponent()
{
    std::cout << "TransformComponent destroyed\n";
}

TransformComponent& TransformComponent::update()
{
    Vector2D product = (velocity * speed);
    rect.x += static_cast<int>(product.x);
    rect.y += static_cast<int>(product.y);

    return *this;
}

TransformComponent& TransformComponent::set_position(int x, int y)
{
    //position = { static_cast<float>(x), static_cast<float>(y) };
    rect.x = x;
    rect.y = y;

    return *this;
}

TransformComponent& TransformComponent::set_rect(const SDL_Rect& rect)
{
    this->rect = rect;

    return *this;
}

TransformComponent& TransformComponent::reset_scale(int s)
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
    rect.w *= (static_cast<float>(scale)/ static_cast<float>(this->scale));
    rect.h *= (static_cast<float>(scale) / static_cast<float>(this->scale));
    this->scale = scale;

    return *this;
}

std::shared_ptr<TransformComponent> TransformComponent::get_ptr()
{
    return shared_from_this();
}
