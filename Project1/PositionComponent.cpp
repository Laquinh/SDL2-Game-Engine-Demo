#include "PositionComponent.hpp"

PositionComponent::PositionComponent() :
    x(0), y(0)
{
    std::cout << this << "\n";
    std::cout << "PositionComponent constructed\n";
}

PositionComponent::PositionComponent(int x, int y):
    x(x), y(y)
{
    std::cout << this << "\n";
    std::cout << "PositionComponent constructed\n";
}

PositionComponent::~PositionComponent()
{
    std::cout << "PositionComponent destroyed\n";
}

int PositionComponent::get_x()
{
    return x;
}

int PositionComponent::get_y()
{
    return y;
}

void PositionComponent::init()
{
}

void PositionComponent::update()
{
    ++x;
    ++y;
}

void PositionComponent::draw()
{
}

void PositionComponent::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::shared_ptr<PositionComponent> PositionComponent::get_ptr()
{
    return shared_from_this();
}
