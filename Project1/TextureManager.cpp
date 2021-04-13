#include "TextureManager.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"
#include "destroyers.hpp"

#include <iostream>
#include <memory>
#include <map>

namespace TextureManager
{
    void init(const std::shared_ptr<CameraComponent>& pCamera)
    {
        camera = pCamera;
    }

    std::shared_ptr<SDL_Texture> load_texture(std::string file)
    {
        const auto& it = textures.find(file);
        if (it == textures.end())
        {
            unique_SDL_Surface tempSurface(IMG_Load(file.c_str()));
            std::shared_ptr<SDL_Texture> tex(SDL_CreateTextureFromSurface(Game::renderer.get(), tempSurface.get()), SDL_DestroyTexture);

            textures.insert(std::pair<std::string, std::shared_ptr<SDL_Texture>>(file, tex));

            return tex;
        }
        else
        {
            return it->second;
        }
    }

    void draw(SDL_Texture& tex, const Rectangle& src, Rectangle dest)
    {
        dest.set_position(dest.x - camera->rect.x, dest.y - camera->rect.y);
        SDL_Rect s = src.get_SDL_Rect();
        SDL_Rect d = dest.get_SDL_Rect();
        SDL_RenderCopy(Game::renderer.get(), &tex, &s, &d);
    }
}