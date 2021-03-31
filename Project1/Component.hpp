#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

#include <iostream>
#include <memory>

using ComponentID = size_t;

inline ComponentID get_component_type_ID() {
	static ComponentID currentID = 0;
	return currentID++;
}

template <typename T>
ComponentID get_component_type_ID()
{
	static ComponentID typeID = get_component_type_ID();
	return typeID;
}

class Entity;

class Component
{
public:
	std::weak_ptr<Entity> entity;

	Component();
	virtual ~Component();

	virtual void init();
	virtual void update();
	virtual void draw();
};

#endif