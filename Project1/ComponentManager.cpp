#include "ComponentManager.hpp"
#include "SDL.h"
#include "Game.hpp"

ComponentManager::ComponentManager() {
}

ComponentManager::~ComponentManager()
{
	for (auto& e : entities) e->destroy();
	refresh();
}

void ComponentManager::update()
{
	for (auto& e : entities) e->update();
}

void ComponentManager::draw()
{
	for (auto& e : entities) e->draw();
}

void ComponentManager::handle_events()
{
	while (SDL_PollEvent(&Game::event)) {
		for (auto& e : entities) e->handle_events();
	}
}

void ComponentManager::refresh()
{
	for (int i = 0; i < maxGroups; ++i)
	{
		auto& v(groupedEntities[i]);
		v.erase(std::remove_if(std::begin(v), std::end(v),
			[i](const std::shared_ptr<Entity>& e)
			{
				return !(e->is_active()) || !(e->has_group(i));
			}),
			std::end(v));	
	}

	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::shared_ptr<Entity>& entity)
		{
			return !(entity->is_active());
		}),
		std::end(entities));
}

Entity& ComponentManager::add_entity()
{
	//std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.emplace_back(std::move(std::make_shared<Entity>(weak_from_this())));
	return *entities.back();
}

void ComponentManager::add_to_group(const std::shared_ptr<Entity>& e, Group g)
{
	groupedEntities[g].emplace_back(e);
}

std::vector<std::shared_ptr<Entity>>& ComponentManager::get_group(Group g)
{
	return groupedEntities[g];
}

void ComponentManager::draw_group(Group g)
{
	auto& v = get_group(g);
	for (auto& e : v)
	{
		e->draw();
	}
}
