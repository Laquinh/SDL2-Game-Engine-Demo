#include "Component.hpp"

Component::Component() {
	std::cout << "Component created\n";
}

void Component::init()
{
}

void Component::update()
{
}

void Component::draw()
{
}

Component::~Component()
{
	std::cout << "Component destroyed\n";
}