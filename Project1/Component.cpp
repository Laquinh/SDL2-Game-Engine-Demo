#include "Component.hpp"

Component::Component() {
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

Component& Component::handle_events()
{
	return *this;
}

Component& Component::destroy()
{
	return *this;
}

Component::~Component()
{
}