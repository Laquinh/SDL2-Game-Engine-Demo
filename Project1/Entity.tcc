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
std::shared_ptr<T> Entity::add_component(TArgs&& ...mArgs)
{
	//T* c = new T(std::forward<TArgs>(mArgs)...);

	std::shared_ptr<T> c(std::make_shared<T>(std::forward<TArgs>(mArgs)...));
	c->entity = weak_from_this();
	componentArray[get_component_type_ID<T>()] = c;
	componentBitset[get_component_type_ID<T>()] = true;

	c->init();

	components.emplace_back(std::move(c));

	return std::dynamic_pointer_cast<T>(components.back());
}

template<typename T>
std::shared_ptr<T> Entity::get_component() const
{
	if (auto p = componentArray[get_component_type_ID<T>()].lock())
	{
		return std::dynamic_pointer_cast<T>(p);
	}
	else
	{
		return std::shared_ptr<T>();
	}
}

#endif