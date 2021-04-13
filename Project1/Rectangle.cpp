#include "Rectangle.hpp"

Rectangle::Rectangle(const SDL_Rect& rect):
	x(rect.x),
	y(rect.y),
	width(rect.w),
	height(rect.h)
{
}

Rectangle::Rectangle(int x, int y, int w, int h):
	x(x),
	y(y),
	width(w),
	height(h)
{
}

Rectangle& Rectangle::set_position(int x, int y)
{
	this->x = x;
	this->y = y;

	return *this;
}

Rectangle& Rectangle::set_position(const Vector2D& vector)
{
	x = vector.x;
	y = vector.y;

	return *this;
}

Vector2D Rectangle::get_position()
{
	return Vector2D(x, y);
}

Rectangle& Rectangle::set_dimensions(int w, int h)
{
	width = w;
	height = h;

	return *this;
}

Rectangle& Rectangle::set_dimensions(const Vector2D& vector)
{
	width = vector.x;
	height = vector.y;

	return *this;
}

Vector2D Rectangle::get_dimensions()
{
	return Vector2D(width, height);
}

SDL_Rect Rectangle::get_SDL_Rect() const
{
	return SDL_Rect{x, y, width, height};
}
