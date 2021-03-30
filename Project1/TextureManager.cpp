#include "TextureManager.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"

#include <iostream>
#include <memory>

unique_SDL_Texture TextureManager::load_texture(std::string file)
{
    unique_SDL_Surface tempSurface(IMG_Load(file.c_str()));
    unique_SDL_Texture tex = (unique_SDL_Texture)SDL_CreateTextureFromSurface(Game::renderer.get(), tempSurface.get());

    return tex;
}
