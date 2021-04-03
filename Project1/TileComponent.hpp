#ifndef TILECOMPONENT_HPP
#define TILECOMPONENT_HPP

#include <string>
#include "SDL.h"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"

class TileComponent : public Component
{
public:
	TileComponent() = default;
	TileComponent(const SDL_Rect& rect, int id);

	TileComponent& init() override;

	static enum Type {
		GRASS,
		DIRT,
		WATER,
		WALL
	};
private:

	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<SpriteComponent> sprite;
	
	SDL_Rect rect;
	int id;
	std::string file;
};

#endif