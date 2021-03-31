#include "PositionComponent.hpp"

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
    x = 0;
    y = 0;
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