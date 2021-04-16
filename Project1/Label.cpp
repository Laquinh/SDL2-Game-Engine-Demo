#include "Label.hpp"
#include "Vector2D.hpp"
#include "AssetManager.hpp"
#include "SDL_ttf.h"
#include "Game.hpp"

Label::Label(const Vector2D& position, const std::string& text, const std::string& font, const SDL_Color& color):
	dest(position.x, position.y, 0, 0),
	text(text),
	font(font),
	color(color)
{
}

Label& Label::init()
{
	unique_SDL_Surface tempSurface(TTF_RenderText_Solid(AssetManager::load_font(font, 13).get(), text.c_str(), color));
	texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(Game::renderer.get(), tempSurface.get()), SDL_DestroyTexture);

	SDL_QueryTexture(texture.get(), nullptr, nullptr, &dest.width, &dest.height);

	dest.width *= 3;
	dest.height *= 3;

	return *this;
}

Label& Label::draw()
{
	AssetManager::draw(*texture, dest, 0);

	return *this;
}
