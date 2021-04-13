#ifndef TILECOMPONENT_HPP
#define TILECOMPONENT_HPP

#include <string>
#include "SDL.h"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "VisibleComponent.hpp"
#include "Rectangle.hpp"

class TileComponent : public Component
{
public:
	TileComponent() = default;
	TileComponent(const Rectangle& rect, int id);
	TileComponent(int row, int column, int width, int height, int id);
	TileComponent& init() override;

	static enum Type {
		GRASS,
		DIRT,
		WATER,
		WALL
	};
private:
	void construct();

	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<VisibleComponent> visible;
	
	Rectangle srcRect, destRect;
	int id;
	std::string file;
};

#endif