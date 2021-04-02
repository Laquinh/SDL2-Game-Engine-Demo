#include "Component.hpp"

Component::Component() {
	std::cout << "Component created\n";
}

Component& Component::init()
{
	return *this;
}

Component& Component::update()
{
	return *this;
}

Component& Component::draw()
{
	return *this;
}

Component::~Component()
{
	std::cout << "Component destroyed\n";
}