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
auto& player(manager->add_entity("alien"));
auto& sign(manager->add_entity());
auto& camera(manager->add_entity());
auto& coin(manager->add_entity("coin"));
auto& coin2(manager->add_entity("coin"));
auto& coin3(manager->add_entity("coin"));
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

		coin.add_component<Coin>();
		coin.add_component<TransformComponent>(SDL_Rect{ 150,150,32,32 });
		coin.add_component<AnimationComponent>("assets/coin-anim.png", SDL_Rect{ 0, 0, 8, 8 })
			.add_animation("turn", { 0, 4, 225 })
			.play("turn");
		coin.add_component<ColliderComponent>();
		coin.add_group(groupMap);

		coin2.add_component<Coin>();
		coin2.add_component<TransformComponent>(SDL_Rect{ 190,150,32,32 });
		coin2.add_component<AnimationComponent>("assets/coin-anim.png", SDL_Rect{ 0, 0, 8, 8 })
			.add_animation("turn", { 0, 4, 225 })
			.play("turn");
		coin2.add_component<ColliderComponent>();
		coin2.add_group(groupMap);

		coin3.add_component<Coin>();
		coin3.add_component<TransformComponent>(SDL_Rect{ 230,150,32,32 });
		coin3.add_component<AnimationComponent>("assets/coin-anim.png", SDL_Rect{ 0, 0, 8, 8 })
			.add_animation("turn", { 0, 4, 225 })
			.play("turn");
		coin3.add_component<ColliderComponent>();
		coin3.add_group(groupMap);

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

	/*auto& pC = player.get_component<ColliderComponent>();

	for (int i = 0; i < colliders.size();)
	{
		if (player.tag != colliders[i]->entity.lock()->tag && (Collision::AABB(pC, *colliders[i])))
		{
			colliders[i]->entity.lock()->destroy();
			manager->refresh();
		}
		else
		{
			++i;
		}
	}*/

	/*colliders.erase(std::remove_if(colliders.begin(), colliders.end(),
		[](const std::shared_ptr<ColliderComponent>& c)
		{
			auto& s = player.get_component<ColliderComponent>();
			if (s.entity.lock()->tag != c->entity.lock()->tag && (Collision::AABB(s, *c)))
			{
				c->entity.lock()->destroy();
				manager->refresh();
				return true;
			}
		}),
		colliders.end());*/

	/*for(int i = 0; i < colliders.size(); ++i)
	{
		auto& s = player.get_component<ColliderComponent>();
		if (s.entity.lock()->tag != colliders[i]->entity.lock()->tag && (Collision::AABB(s, *colliders[i])))
		{
			colliders[i]->entity.lock()->destroy();
			manager->refresh();
			auto pos = std::find(Game::colliders.begin(), Game::colliders.end(), colliders[i]->shared_from_this());
			if (pos != Game::colliders.end())
			{
				Game::colliders.erase(pos);
				--i;
			}
		}
	}*/
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