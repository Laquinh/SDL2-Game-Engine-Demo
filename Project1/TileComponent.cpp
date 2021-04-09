#include "TileComponent.hpp"
#include "ColliderComponent.hpp"

TileComponent::TileComponent(const SDL_Rect& rect, int id):
	destRect(rect),
	id(id-1)
{
	construct();
}

TileComponent::TileComponent(int row, int column, int width, int height, int id):
	destRect({column*width, row*height, width, height}),
	id(id-1)
{
	construct();
}

void TileComponent::construct()
{
	if (this->id <= 20)
	{
		file = "assets/tileset.png";
		this->srcRect = { (this->id % 3) * 16, this->id / 3 * 16, 16, 16 };
	}
	else if(this->id == 21)
	{
		file = "assets/wall.png";
		this->srcRect = { 0, 0, 16, 16 };
	}
	else
	{
		file = "assets/sign.png";
		this->srcRect = { 0, 0, 16, 16 };
	}
}

TileComponent& TileComponent::init()
{
	transform = (entity.lock()->add_component<TransformComponent>(destRect)).shared_from_this();
	sprite = (entity.lock()->add_component<SpriteComponent>(file, false)).set_srcRect(srcRect).shared_from_this();
	if(id == 16) entity.lock()->add_component<ColliderComponent>("water");
	if(id == 21) entity.lock()->add_component<ColliderComponent>("wall");

	return *this;
}
