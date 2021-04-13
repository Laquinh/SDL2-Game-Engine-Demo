#include "TileComponent.hpp"
#include "ColliderComponent.hpp"

TileComponent::TileComponent(const Rectangle& rect, int id):
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
	if (auto e = entity.lock())
	{
		transform = (e->add_component<TransformComponent>(destRect));
		visible = (e->add_component<SpriteComponent>(file, srcRect));
		if (id == 16)
		{
			e->tag = "water";
			e->add_component<ColliderComponent>()->isRigid = true;
		}
		else if (id == 21)
		{
			e->add_component<ColliderComponent>()->isRigid = true;
			e->tag = "wall";
		}
		else
		{
			e->tag = "tile";
		}
	}
	return *this;
}
