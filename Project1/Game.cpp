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
#include "Player.hpp"

#include <iostream>
#include <memory>

/*unique_SDL_Renderer Game::renderer = nullptr;
unique_SDL_Window Game::window = nullptr;
SDL_Event Game::event;
std::vector<std::shared_ptr<ColliderComponent>> Game::colliders = {};*/
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
		window = (unique_SDL_Window)SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
		renderer = (unique_SDL_Renderer)SDL_CreateRenderer(window.get(), -1, 0);

		Map::load_map("assets/level1.map", 20, 20);

		auto& player = Player::create(*scene);
		CameraComponent::create(*scene, w, h, player);

		auto& sign = scene->add_entity("sign");
		sign.add_component<TileComponent>(13, 5, 64, 64, 23);
		sign.add_group(groupMap);

		Coin::create(*scene, SDL_Rect{ 150,150,32,32 });
		Coin::create(*scene, SDL_Rect{ 190,150,32,32 });
		Coin::create(*scene, SDL_Rect{ 230,150,32,32 });

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handle_events()
{
	scene->handle_events();
}

void Game::update()
{
	scene->update();
}

void Game::render()
{
	SDL_RenderClear(renderer.get());
	scene->draw_group(groupMap);
	scene->draw_group(groupPlayers);
	scene->draw_group(groupEnemies);
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();
}

void Game::add_tile(int row, int column, int id)
{
	auto& tile(scene->add_entity());
	tile.add_component<TileComponent>(row, column, 64, 64, id);
	tile.add_group(groupMap);
}

bool Game::is_running()
{
	return isRunning;
}