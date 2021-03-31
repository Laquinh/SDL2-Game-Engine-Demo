#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"

#include <iostream>
#include <memory>
#include <bitset>
#include <array>
#include <vector>

class Component;

constexpr size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;
//using ComponentArray = std::array<std::unique_ptr<Component>, maxComponents>;
using ComponentVector = std::vector<std::shared_ptr<Component>>;

class Entity : public std::enable_shared_from_this<Entity>
{
public:
	Entity();
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
private:
	bool active = true;
	ComponentVector components;

	//ComponentArray componentArray;
	ComponentBitset componentBitset;
};

#include "Entity.tcc"

#endif