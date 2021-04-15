#include "Game.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include "TextureManager.hpp"
#include "Map.hpp"
#include "ColliderComponent.hpp"

#include "Collision.hpp"
#include "TileComponent.hpp"
#include "AnimationComponent.hpp"
#include "Coin.hpp"
#include "Player.hpp"
#include "BulletSpawner.hpp"
#include "Scene.hpp"
#include "CameraComponent.hpp"

#include <iostream>
#include <memory>

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
	scene = std::make_shared<Scene>();

	int flags = 0;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		window = (unique_SDL_Window)SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
		renderer = (unique_SDL_Renderer)SDL_CreateRenderer(window.get(), -1, 0);

		Map::load_map(*scene, "assets/level1.map", 20, 20);

		auto& player = Player::create(*scene);
		Map::add_tile(*scene, 13, 5, 23);

		Coin::create(*scene, Rectangle( 150,150,32,32 ));
		Coin::create(*scene, Rectangle( 190,150,32,32 ));
		Coin::create(*scene, Rectangle( 230,150,32,32 ));

		CameraComponent::create(*scene, w, h, player);

		BulletSpawner::create(*scene);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::update()
{
	scene->update();
}

void Game::handle_events()
{
	scene->handle_events();
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

bool Game::is_running()
{
	return isRunning;
}