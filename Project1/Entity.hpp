#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include "ComponentManager.hpp"

#include <iostream>
#include <memory>
#include <bitset>
#include <array>
#include <vector>

class Component;
class ComponentManager;

constexpr size_t maxComponents = 32;
#ifndef DEFINED_maxGroups
constexpr size_t maxGroups = 32;
#define DEFINED_maxGroups
#endif

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<std::weak_ptr<Component>, maxComponents>;
using ComponentVector = std::vector<std::shared_ptr<Component>>;

using Group = size_t;
using GroupBitset = std::bitset<maxGroups>;

class Entity : public std::enable_shared_from_this<Entity>
{
public:
	Entity(const std::weak_ptr<ComponentManager>& manager);
	~Entity();

	void update();
	void draw();
	bool is_active() const;
	void destroy();
	
	template <typename T>
	bool has_component() const;

	template <typename T, typename ...TArgs>
	T& add_component(TArgs&& ...mArgs);

	template <typename T>
	T& get_component() const;

	bool has_group(Group group);
	void add_group(Group group);
	void remove_group(Group group);
private:
	std::weak_ptr<ComponentManager> manager;
	bool active = true;

	ComponentVector components;
	ComponentArray componentArray;
	ComponentBitset componentBitset;

	GroupBitset groupBitset;
};

#include "Entity.tcc"

#endif