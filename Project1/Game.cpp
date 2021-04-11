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
#include "AnimationComponent.hpp"
#include "Coin.hpp"

#include <iostream>
#include <memory>

/*unique_SDL_Renderer Game::renderer = nullptr;
unique_SDL_Window Game::window = nullptr;
SDL_Event Game::event;
std::vector<std::shared_ptr<ColliderComponent>> Game::colliders = {};*/

std::shared_ptr<ComponentManager> manager = std::make_shared<ComponentManager>();
std::unique_ptr<Map> map;

enum GroupLabels : std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders,
	groupCamera
};

Game::Game(std::string title, int x, int y, int w, int h, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		auto& player = manager->add_entity("alien");
		auto& sign = manager->add_entity("sign");
		auto& camera = manager->add_entity("camera");

		window = (unique_SDL_Window)SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
		renderer = (unique_SDL_Renderer)SDL_CreateRenderer(window.get(), -1, 0);

		player.add_component<TransformComponent>(SDL_Rect{ 50, 150, 96, 96 });
		player.add_component<AnimationComponent>("assets/alien-anim.png", SDL_Rect{ 0, 0, 24, 24 })
			.add_animation("idle", { 0, 4, 225 })
			.add_animation("walk", { 1, 4, 100 })
			.play("idle");
		player.add_component<KeyboardController>();
		player.add_component<ColliderComponent>();
		player.add_group(groupPlayers);

		camera.add_component<CameraComponent>(player.get_component<TransformComponent>().shared_from_this(), SDL_Rect{ 0,0,w,h });
		TextureManager::init(camera.get_component<CameraComponent>().shared_from_this());

		Map::load_map("assets/level1.map", 20, 20);

		sign.add_component<TileComponent>(13, 5, 64, 64, 23);
		sign.add_group(groupMap);

		Coin::create(*manager, SDL_Rect{ 150,150,32,32 });
		Coin::create(*manager, SDL_Rect{ 190,150,32,32 });
		Coin::create(*manager, SDL_Rect{ 230,150,32,32 });

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handle_events()
{
	manager->handle_events();
}

void Game::update()
{
	manager->update();
}

void Game::render()
{
	SDL_RenderClear(renderer.get());
	manager->draw_group(groupMap);
	manager->draw_group(groupPlayers);
	manager->draw_group(groupEnemies);
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();
}

void Game::add_tile(int row, int column, int id)
{
	auto& tile(manager->add_entity());
	tile.add_component<TileComponent>(row, column, 64, 64, id);
	tile.add_group(groupMap);
}

bool Game::is_running()
{
	return isRunning;
}