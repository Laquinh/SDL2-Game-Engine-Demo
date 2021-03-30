#include "GameObject.hpp"

GameObject::GameObject(std::string file, SDL_Renderer& renderer, int x, int y) :
	renderer((unique_SDL_Renderer)&renderer),
	texture(TextureManager::load_texture(file, renderer)),
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
	SDL_RenderCopy(renderer.get(), texture.get(), &srcRect, &destRect);
}
