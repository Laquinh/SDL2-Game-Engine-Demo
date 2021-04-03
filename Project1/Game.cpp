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
std::unique_ptr<Map> map;
std::vector<std::shared_ptr<ColliderComponent>> Game::colliders = {};

ComponentManager manager;
auto& wall(manager.add_entity());
auto& wall2(manager.add_entity());
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

		scientist.add_component<TransformComponent>(50, 50).set_rect({ 3, 0, 10, 16 }).set_scale(2).reset_scale();
		scientist.add_component<SpriteComponent>("assets/scientist.png", SDL_Rect{ 3, 0, 10, 16 });
		scientist.add_component<KeyboardController>();
		scientist.add_component<ColliderComponent>("scientist");

		wall.add_component<TileComponent>(SDL_Rect{ 256, 256, 32, 32 }, TileComponent::Type::WALL);
		wall.add_component<ColliderComponent>("wall");
		wall2.add_component<TileComponent>(SDL_Rect{ 512, 256, 32, 32 }, TileComponent::Type::DIRT);
		wall2.add_component<ColliderComponent>("dirt");

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