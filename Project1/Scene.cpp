#include "Scene.hpp"
#include "SDL.h"
#include "Game.hpp"
#include "Collision.hpp"

Scene::Scene() {
}

Scene::~Scene()
{
	for (auto& e : entities) e->destroy();
	//refresh();
}

void Scene::update()
{
	for (int i = 0; i < Game::colliders.size(); ++i)
	{
		for (int j = i+1; j < Game::colliders.size(); ++j)
		{
			if (Collision::AABB(*Game::colliders[i], *Game::colliders[j]))
			{
				int first = Game::colliders.size();
				std::weak_ptr<ColliderComponent> col1 = Game::colliders[i];

				Game::colliders[i]->entity.lock()->onCollision(*Game::colliders[j]->entity.lock());
				if (first != Game::colliders.size()) //if some collider was destroyed
				{
					if (auto p = col1.lock()) //if [i] still exists
					{
						--j; //Then [j] was destroyed
						continue;
					}
					else //if [i] no longer exists
					{
						--i; //Then [i] was destroyed
						break;
					}
				}
				Game::colliders[j]->entity.lock()->onCollision(*Game::colliders[i]->entity.lock());
				if (first != Game::colliders.size()) //if some collider was destroyed
				{
					if (auto p = col1.lock()) //if [i] still exists
					{
						--j; //Then [j] was destroyed
						continue;
					}
					else //if [i] no longer exists
					{
						--i; //Then [i] was destroyed
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < entities.size(); ++i)
	{
		auto first = entities.size();
		entities[i]->update();
		if (first != entities.size()) //if some collider was destroyed
		{
			--i; //Then [i] was destroyed
			break;
		}
	}
}

void Scene::draw()
{
	for (auto& e : entities) e->draw();
}

void Scene::handle_events()
{
	while (SDL_PollEvent(&Game::event)) {
		for (int i = 0; i < entities.size(); ++i)
		{
			entities[i]->handle_events(Game::event);
		}
	}
}

void Scene::refresh()
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

Entity& Scene::add_entity(const std::string& tag)
{
	//std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.emplace_back(std::move(std::make_shared<Entity>(weak_from_this())))->tag = tag;
	return *entities.back();
}

std::shared_ptr<Entity> Scene::get_entity_with_tag(const std::string& tag)
{
	for (auto& e : entities)
	{
		if (e->tag == tag)
		{
			return e;
		}
	}
	return std::shared_ptr<Entity>();
}

void Scene::add_to_group(const std::shared_ptr<Entity>& e, Group g)
{
	groupedEntities[g].emplace_back(e);
}

std::vector<std::shared_ptr<Entity>>& Scene::get_group(Group g)
{
	return groupedEntities[g];
}

void Scene::draw_group(Group g)
{
	auto& v = get_group(g);
	for (auto& e : v)
	{
		e->draw();
	}
}
