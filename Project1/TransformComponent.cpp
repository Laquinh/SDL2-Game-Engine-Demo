#include "TransformComponent.hpp"

TransformComponent::TransformComponent() :
    //position({0, 0})
    x(0), y(0)
{
    std::cout << this << "\n";
    std::cout << "TransformComponent constructed\n";
}

TransformComponent::TransformComponent(int x, int y):
    //position({ static_cast<float>(x), static_cast<float>(y) })
    x(x), y(y)
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
    ++x;
    ++y;
}

void TransformComponent::draw()
{
}

void TransformComponent::set_position(int x, int y)
{
    //position = { static_cast<float>(x), static_cast<float>(y) };
    this->x = x;
    this->y = y;
}

std::shared_ptr<TransformComponent> TransformComponent::get_ptr()
{
    return shared_from_this();
}
