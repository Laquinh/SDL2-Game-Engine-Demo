#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "SDL.h"
#include "Vector2D.hpp"

struct Rectangle
{
	Rectangle() = default;
	Rectangle(const SDL_Rect& rect);
	Rectangle(int x, int y, int w, int h);
	~Rectangle() = default;

	Rectangle& set_position(int x, int y);
	Rectangle& set_position(const Vector2D& vector);
	Vector2D get_position();
	Rectangle& set_dimensions(int w, int h);
	Rectangle& set_dimensions(const Vector2D& vector);
	Vector2D get_dimensions();

	SDL_Rect get_SDL_Rect() const;

	int x, y, width, height;
};

#endif