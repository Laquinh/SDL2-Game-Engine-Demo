#include "Entity.hpp"
#include <memory>

Entity::Entity()
{
	std::cout << "Entity created\n";
}

Entity::~Entity()
{
	std::cout << "Entity destroyed\n";
}

void Entity::update()
{
	for (auto& c : components)
	{
		c->update();
	}
}

void Entity::draw()
{
	for (auto& c : components) c->draw();
}

bool Entity::is_active() const
{
	return active;
}

void Entity::destroy()
{
	active = false;
}