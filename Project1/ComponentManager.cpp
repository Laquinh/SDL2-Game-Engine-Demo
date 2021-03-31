#include "ComponentManager.hpp"

ComponentManager::ComponentManager() {
	std::cout << "ComponentManager created\n";
}

ComponentManager::~ComponentManager()
{
	for (auto& e : entities) e->destroy();
	refresh();
	std::cout << "ComponentManager destroyed\n";
}

void ComponentManager::update()
{
	for (auto& e : entities) e->update();
}

void ComponentManager::draw()
{
	for (auto& e : entities) e->draw();
}

void ComponentManager::refresh()
{
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
	entities.emplace_back(std::move(std::make_shared<Entity>()));
	return *entities.back();
}