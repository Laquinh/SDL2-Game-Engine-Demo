#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "Entity.hpp"
#include "Component.hpp"

using EntityVector = std::vector<std::shared_ptr<Entity>>;

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	void update();
	void draw();
	void refresh();
	Entity& add_entity();
private:
	EntityVector entities;
};

#endif