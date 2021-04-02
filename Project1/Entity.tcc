#ifndef ENTITY_TCC
#define ENTITY_TCC

#include <iostream>

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

template <typename T>
bool Entity::has_component() const
{
	return componentBitset[get_component_type_ID<T>()];
}

template<typename T, typename ...TArgs>
T& Entity::add_component(TArgs && ...mArgs)
{
	//T* c = new T(std::forward<TArgs>(mArgs)...);

	std::shared_ptr<T> c(std::make_shared<T>(std::forward<TArgs>(mArgs)...));
	c->entity = weak_from_this();
	componentArray[get_component_type_ID<T>()] = c;
	componentBitset[get_component_type_ID<T>()] = true;

	c->init();

	components.emplace_back(std::move(c));

	return dynamic_cast<T&>(*(components.back()));
}

template<typename T>
T& Entity::get_component() const
{
	return dynamic_cast<T&>(*(componentArray[get_component_type_ID<T>()].lock()));
}

#endif