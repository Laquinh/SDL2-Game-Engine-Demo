#include "Game.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ColliderComponent.hpp"

#include "ECS.hpp"
#include "Collision.hpp"
#include "TileComponent.hpp"

#include <iostream>
#include <memory>

/*unique_SDL_Renderer Game::renderer = nullptr;
unique_SDL_Window Game::window = nullptr;
SDL_Event Game::event;
std::vector<std::shared_ptr<ColliderComponent>> Game::colliders = {};*/

std::shared_ptr<ComponentManager> manager = std::make_shared<ComponentManager>();
auto& scientist(manager->add_entity());
auto& sign(manager->add_entity());
std::unique_ptr<Map> map;

enum GroupLabels : std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

Game::Game(std::string title, int x, int y, int w, int h, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialised...\n";

		window = (unique_SDL_Window)SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
		if (window)
		{
			std::cout << "Window created\n";
		}

		renderer = (unique_SDL_Renderer)SDL_CreateRenderer(window.get(), -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer.get(), 255, 0, 0, 255);
			std::cout << "Renderer created\n";
		}

		Map::load_map("assets/level1.map", 20, 20);

		scientist.add_component<TransformComponent>(SDL_Rect{ 50, 50, 48, 48 });
		scientist.add_component<SpriteComponent>("assets/alien-idle.png", 4, 110);
		scientist.add_component<KeyboardController>();
		scientist.add_component<ColliderComponent>("scientist");
		scientist.add_group(groupPlayers);

		sign.add_component<TileComponent>(13, 5, 32, 32, 23);
		sign.add_group(groupMap);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handle_events()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	SDL_Rect scientistPos = scientist.get_component<TransformComponent>().get_rect();
	manager->update();
	
	for (const auto& c : colliders)
	{
		auto& s = scientist.get_component<ColliderComponent>();
		if (s.tag != c->tag && (Collision::AABB(s, *c)))
		{
			scientist.get_component<TransformComponent>().rect = scientistPos;
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer.get());
	/*manager.draw();
	scientist.draw();*/
	manager->draw_group(groupMap);
	manager->draw_group(groupPlayers);
	manager->draw_group(groupEnemies);
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();

	std::cout << "Game cleaned\n";
}

void Game::add_tile(int row, int column, int id)
{
	auto& tile(manager->add_entity());
	tile.add_component<TileComponent>(row, column, 32, 32, id);
	tile.add_group(groupMap);
}

bool Game::is_running()
{
	return isRunning;
}