#ifndef ENTITY_TCC
#define ENTITY_TCC

#include <iostream>

inline size_t get_component_type_ID();
template <typename T>
size_t get_component_type_ID();

template <typename T>
bool Entity::has_component() const
{
	return componentBitset[get_component_type_ID<T>()];
}

template<typename T, typename ...TArgs>
T& Entity::add_component(TArgs && ...mArgs)
{
	//T* c = new T(std::forward<TArgs>(mArgs)...);

	std::unique_ptr<T> unique_c(std::make_unique<T>(std::forward<TArgs>(mArgs)...));
	unique_c->entity = weak_from_this();
	//componentArray[get_component_type_ID<T>()] = std::unique_ptr<T>(c);
	componentBitset[get_component_type_ID<T>()] = true;

	unique_c->init();

	components.emplace_back(std::move(unique_c));

	return dynamic_cast<T&>(*(components.back()));
}

template<typename T>
T& Entity::get_component() const
{
	return dynamic_cast<T&>(*(components[get_component_type_ID<T>()]));
}

#endif