#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(std::string file, int x, int y) :
	texture(TextureManager::load_texture(file)),
	x(x), y(y),
	srcRect({ 0, 0, 0, 0 }),
	destRect({ 0, 0, 0, 0 })
{
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	++x;
	++y;
	
	srcRect.w = 16;
	srcRect.h = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
	destRect.x = x;
	destRect.y = y;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer.get(), texture.get(), &srcRect, &destRect);
}
