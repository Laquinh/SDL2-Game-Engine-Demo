#include "ComponentManager.hpp"
#include "SDL.h"
#include "Game.hpp"
#include "Collision.hpp"

ComponentManager::ComponentManager() {
}

ComponentManager::~ComponentManager()
{
	for (auto& e : entities) e->destroy();
	//refresh();
}

void ComponentManager::update()
{
	for (int i = 0; i < Game::colliders.size(); ++i)
	{
		for (int j = i; j < Game::colliders.size(); ++j)
		{
			if (Collision::AABB(*Game::colliders[i], *Game::colliders[j]) && i != j)
			{
				int first = Game::colliders.size();
				Game::colliders[i]->entity.lock()->onCollision(*Game::colliders[j]->entity.lock());
				if (first != Game::colliders.size())
				{
					--j;
					continue;
				}
				Game::colliders[j]->entity.lock()->onCollision(*Game::colliders[i]->entity.lock());
				if (first != Game::colliders.size())
				{
					--i;
				}
			}
		}
	}
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
				if (!(e->is_active()) || !(e->has_group(i)))
				{
					return true;
				}
				else
				{
					return false;
				}
			}),
			std::end(v));	
	}

	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::shared_ptr<Entity>& entity)
		{
			if (!(entity->is_active()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}),
		std::end(entities));
}

Entity& ComponentManager::add_entity(const std::string& tag)
{
	//std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.emplace_back(std::move(std::make_shared<Entity>(weak_from_this())))->tag = tag;
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
