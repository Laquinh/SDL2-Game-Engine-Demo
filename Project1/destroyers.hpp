#ifndef DESTROYERS_HPP
#define DESTROYERS_HPP

#include "SDL.h"
#include <memory>

template <auto delete_function>
struct TypeDestroyer
{
	template <class T>
	void operator()(T* ptr)
	{
		delete_function(ptr);
	}
};

using unique_SDL_Window = std::unique_ptr<SDL_Window, TypeDestroyer<SDL_DestroyWindow>>;
using unique_SDL_Renderer = std::unique_ptr<SDL_Renderer, TypeDestroyer<SDL_DestroyRenderer>>;
using unique_SDL_Surface = std::unique_ptr<SDL_Surface, TypeDestroyer<SDL_FreeSurface>>;
using unique_SDL_Texture = std::unique_ptr<SDL_Texture, TypeDestroyer<SDL_DestroyTexture>>;

#endif