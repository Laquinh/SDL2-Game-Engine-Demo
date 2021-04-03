#include "TileComponent.hpp"

TileComponent::TileComponent(const SDL_Rect& rect, int id):
	rect(rect),
	id(id)
{
	switch (id)
	{
	case GRASS:
		file = "assets/grass.png";
		break;
	case DIRT:
		file = "assets/dirt.png";
		break;
	case WATER:
		file = "assets/water.png";
		break;
	case WALL:
		file = "assets/wall.png";
	}
}

TileComponent& TileComponent::init()
{
	transform = (entity.lock()->add_component<TransformComponent>(rect)).shared_from_this();
	sprite = (entity.lock()->add_component<SpriteComponent>(file)).shared_from_this();

	return *this;
}
