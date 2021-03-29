#ifndef DESTROYERS_HPP
#define DESTROYERS_HPP

#include "SDL.h"
#include <memory>

struct SDL_Window_Destroyer
{
	void operator()(SDL_Window* w) const;
};
typedef std::unique_ptr<SDL_Window, SDL_Window_Destroyer> unique_SDL_Window;

struct SDL_Renderer_Destroyer
{
	void operator()(SDL_Renderer* r) const;
};
typedef std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> unique_SDL_Renderer;

struct SDL_Surface_Destroyer
{
	void operator()(SDL_Surface* s) const;
};
typedef std::unique_ptr<SDL_Surface, SDL_Surface_Destroyer> unique_SDL_Surface;

struct SDL_Texture_Destroyer
{
	void operator()(SDL_Texture* s) const;
};
typedef std::unique_ptr<SDL_Texture, SDL_Texture_Destroyer> unique_SDL_Texture;

#endif