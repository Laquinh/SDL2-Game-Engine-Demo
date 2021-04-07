#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "Entity.hpp"
#include "Component.hpp"

#include <array>
#include <vector>
#include <memory>

class Entity;

#ifndef DEFINED_maxGroups
constexpr size_t maxGroups = 32;
#define DEFINED_maxGroups
#endif

using EntityVector = std::vector<std::shared_ptr<Entity>>;
using GroupArray = std::array<EntityVector, maxGroups>;

using Group = size_t;

class ComponentManager : public std::enable_shared_from_this<ComponentManager>
{
public:
	ComponentManager();
	~ComponentManager();
	void update();
	void draw();
	void refresh();
	Entity& add_entity();
	void add_to_group(const std::shared_ptr<Entity>& e, Group g);
	EntityVector& get_group(Group g);
	void draw_group(Group g);
private:
	EntityVector entities;
	GroupArray groupedEntities;
};

#endif