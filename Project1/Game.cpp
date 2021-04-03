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

unique_SDL_Renderer Game::renderer = nullptr;
unique_SDL_Window Game::window = nullptr;
SDL_Event Game::event;
std::vector<std::shared_ptr<ColliderComponent>> Game::colliders = {};

ComponentManager manager;
auto& scientist(manager.add_entity());
std::unique_ptr<Map> map;

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

		window = (unique_SDL_Window)SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen);
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

		scientist.add_component<TransformComponent>(50, 50).set_rect({ 3, 0, 10, 16 }).set_scale(2).reset_scale();
		scientist.add_component<SpriteComponent>("assets/scientist.png", SDL_Rect{ 3, 0, 10, 16 });
		scientist.add_component<KeyboardController>();
		scientist.add_component<ColliderComponent>("scientist");

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
	manager.update();
	
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
	manager.draw();
	scientist.draw();
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();

	std::cout << "Game cleaned\n";
}

void Game::add_tile(int x, int y, int id)
{
	auto& tile(manager.add_entity());
	tile.add_component<TileComponent>(SDL_Rect{ x * 32, y * 32, 32, 32 }, id);
}

bool Game::is_running()
{
	return isRunning;
}