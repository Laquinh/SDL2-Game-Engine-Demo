#include "destroyers.hpp"

#include "SDL.h"

#include <memory>
#include <iostream>

void SDL_Window_Destroyer::operator()(SDL_Window* w) const
{
	SDL_DestroyWindow(w);

	std::cout << "Window destroyed\n";
}

void SDL_Renderer_Destroyer::operator()(SDL_Renderer* r) const
{
	SDL_DestroyRenderer(r);

	std::cout << "Renderer destroyed\n";
}

void SDL_Surface_Destroyer::operator()(SDL_Surface* s) const
{
	SDL_FreeSurface(s);

	std::cout << "Surface destroyed\n";
}

void SDL_Texture_Destroyer::operator()(SDL_Texture* t) const
{
	SDL_DestroyTexture(t);

	std::cout << "Texture destroyed\n";
}