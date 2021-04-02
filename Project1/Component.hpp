#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

#include <iostream>
#include <memory>

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