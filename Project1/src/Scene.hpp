#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "constants.hpp"

#include <array>
#include <vector>
#include <memory>
#include <string>

class Entity;

class Scene : public std::enable_shared_from_this<Scene>
{
public:
	Scene();
	~Scene();
	void update();
	void draw();
	void handle_events();
	void refresh();
	Entity& add_entity(const std::string& tag = "");
	std::shared_ptr<Entity> get_entity_with_tag(const std::string& tag);

	void add_to_group(const std::shared_ptr<Entity>& e, Group g);
	std::vector<std::shared_ptr<Entity>>& get_group(Group g);
	void draw_group(Group g);
private:
	std::vector<std::shared_ptr<Entity>> entities;
	std::array<std::vector<std::shared_ptr<Entity>>, maxGroups> groupedEntities;
};

#endif