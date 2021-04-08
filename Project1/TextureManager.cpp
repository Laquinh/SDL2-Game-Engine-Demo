#include "TextureManager.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"
#include "destroyers.hpp"

#include <iostream>
#include <memory>
#include <map>

/*void del(SDL_Texture* t)
{
    SDL_DestroyTexture(t);
    std::cout << t << " texture deleted\n";
}*/

std::shared_ptr<SDL_Texture> TextureManager::load_texture(std::string file)
{
    const auto& it = textures.find(file);
    if (it == textures.end())
    {
        unique_SDL_Surface tempSurface(IMG_Load(file.c_str()));
        std::shared_ptr<SDL_Texture> tex(SDL_CreateTextureFromSurface(Game::renderer.get(), tempSurface.get()), SDL_DestroyTexture);

        textures.insert(std::pair<std::string, std::shared_ptr<SDL_Texture>>(file, tex));

        //std::cout << "Making texture (" << tex.get() << ") of \"" << file << "\" with count of " << tex.use_count() << "\n";

        return tex;
    }
    else
    {
        //std::cout << "Using texture (" << it->second.get() << ") of \"" << file << "\" with count of " << (it->second).use_count() << "\n";
        return it->second;
    }
}

void TextureManager::draw(SDL_Texture& tex, const SDL_Rect& src, const SDL_Rect& dest)
{
    SDL_RenderCopy(Game::renderer.get(), &tex, &src, &dest);
}

