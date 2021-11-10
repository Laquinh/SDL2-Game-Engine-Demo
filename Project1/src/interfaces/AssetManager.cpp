#include "AssetManager.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "../Game.hpp"
#include "../destroyers.hpp"
#include "../components/CameraComponent.hpp"

#include <iostream>
#include <memory>
#include <map>

namespace AssetManager
{
    void init(const std::shared_ptr<CameraComponent>& pCamera)
    {
        camera = pCamera;
    }

    void draw(SDL_Texture& tex, const Rectangle& src, Rectangle dest, double angle)
    {
        SDL_Point point = { dest.width / 2, dest.height / 2 };
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        dest.set_position(dest.x - camera->rect.x, dest.y - camera->rect.y);
        SDL_Rect s = src.get_SDL_Rect();
        SDL_Rect d = dest.get_SDL_Rect();
        SDL_RenderCopyEx(Game::renderer.get(), &tex, &s, &d, angle, &point, flip);
    }

    void draw(SDL_Texture& tex, Rectangle dest, double angle)
    {
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        dest.set_position(dest.x - camera->rect.x, dest.y - camera->rect.y);
        SDL_Rect d = dest.get_SDL_Rect();
        SDL_RenderCopyEx(Game::renderer.get(), &tex, nullptr, &d, angle, nullptr, flip);
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

    std::shared_ptr<TTF_Font> load_font(std::string file, int fontSize)
    {
        const auto& it = fonts.find(file);
        if (it == fonts.end())
        {
            std::shared_ptr<TTF_Font> font(TTF_OpenFont(file.c_str(), fontSize), TTF_CloseFont);

            fonts.insert(std::pair<std::string, std::shared_ptr<TTF_Font>>(file, font));

            return font;
        }
        else
        {
            return it->second;
        }
    }
}