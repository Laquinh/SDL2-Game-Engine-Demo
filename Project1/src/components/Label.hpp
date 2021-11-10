#pragma once
#ifndef LABEL_HPP
#define LABEL_HPP

#include "Component.hpp"
#include "Rectangle.hpp"
#include "SDL.h"
#include <string>

struct Vector2D;

class Label : public Component
{
public:
	Label(const Vector2D& position, const std::string& text, const std::string& font, const SDL_Color& color);

	Label& init() override;
	Label& draw() override;
private:
	Rectangle dest;
	std::string text;
	std::string font;
	SDL_Color color;
	std::shared_ptr<SDL_Texture> texture;
};

#endif