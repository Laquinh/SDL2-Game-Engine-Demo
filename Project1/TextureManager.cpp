#include "TextureManager.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <memory>

unique_SDL_Texture TextureManager::load_texture(std::string file, SDL_Renderer& renderer)
{
    unique_SDL_Surface tempSurface(IMG_Load(file.c_str()));
    unique_SDL_Texture tex = (unique_SDL_Texture)SDL_CreateTextureFromSurface(&renderer, tempSurface.get());

    return tex;
}
