#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <memory>

class Entity;
union SDL_Event;

class Component
{
public:
	std::weak_ptr<Entity> entity;

	Component();
	virtual ~Component();

	virtual Component& init();
	virtual Component& update();
	virtual Component& draw();
	virtual Component& handle_events(const SDL_Event& event);
	virtual Component& destroy();
	virtual Component& onCollision(Entity& e);
};

#endif