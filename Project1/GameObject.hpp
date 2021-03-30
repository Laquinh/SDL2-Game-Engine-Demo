#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "SDL.h"
#include "destroyers.hpp"
#include "TextureManager.hpp"
#include <iostream>

class GameObject
{
public:
	GameObject(std::string file, SDL_Renderer& renderer, int x, int y);
	~GameObject();

	void update();
	void render();
private:
	int x;
	int y;

	unique_SDL_Texture texture;
	unique_SDL_Renderer renderer;
	SDL_Rect srcRect, destRect;
};

#endif