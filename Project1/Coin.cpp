#include "Coin.hpp"
#include "TransformComponent.hpp"
#include "AnimationComponent.hpp"
#include "ColliderComponent.hpp"
#include "Player.hpp"

Coin& Coin::onCollision(Entity& e)
{
    if (e.tag == "player")
    {
		++e.get_component<Player>()->money;
        entity.lock()->destroy();
    }

    return *this;
}

Entity& Coin::create(Scene& scene, const SDL_Rect& destRect)
{
	auto& coin = scene.add_entity("coin");
	coin.add_component<Coin>();
	coin.add_component<TransformComponent>(destRect);
	coin.add_component<AnimationComponent>("assets/coin-anim.png", SDL_Rect{ 0, 0, 8, 8 })
		->add_animation("turn", { 0, 4, 225 })
		.play("turn");
	coin.add_component<ColliderComponent>();
	coin.add_group(0);

	return coin;
}
