#include "Game.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

#include "ComponentManager.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"

#include <iostream>
#include <memory>

unique_SDL_Renderer Game::renderer = nullptr;
unique_SDL_Window Game::window = nullptr;

std::unique_ptr<Map> map;

ComponentManager manager;
auto& scientist(manager.add_entity());

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

		map = std::make_unique<Map>();

		scientist.add_component<TransformComponent>(50, 50);
		scientist.add_component<SpriteComponent>("assets/scientist.png");
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handle_events()
{
	SDL_Event event;
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
	manager.update();
	//std::cout << scientist.get_component<TransformComponent>().position << "\n";
}

void Game::render()
{
	SDL_RenderClear(renderer.get());
	map->draw_map();
	manager.draw();
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();

	std::cout << "Game cleaned\n";
}

bool Game::is_running()
{
	return isRunning;
}