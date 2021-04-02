#include "TransformComponent.hpp"

TransformComponent::TransformComponent() :
    //position({0, 0})
    position({ 0, 0 }),
    velocity({ 0, 0 }),
    speed(3)
{
    std::cout << this << "\n";
    std::cout << "TransformComponent constructed\n";
}

TransformComponent::TransformComponent(int x, int y):
    //position({ static_cast<float>(x), static_cast<float>(y) })
    position({static_cast<float>(x), static_cast<float>(y)}),
    velocity({ 0, 0 }),
    speed(3)
{
    std::cout << this << "\n";
    std::cout << "TransformComponent constructed\n";
}

TransformComponent::~TransformComponent()
{
    std::cout << "TransformComponent destroyed\n";
}

void TransformComponent::init()
{
}

void TransformComponent::update()
{
    Vector2D test = (velocity * speed);
    position += test;
    std::cout << test << " and " << position << " and " << velocity << "\n";
}

void TransformComponent::draw()
{
}

void TransformComponent::set_position(int x, int y)
{
    //position = { static_cast<float>(x), static_cast<float>(y) };
    position = { static_cast<float>(x), static_cast<float>(y) };
}

std::shared_ptr<TransformComponent> TransformComponent::get_ptr()
{
    return shared_from_this();
}
