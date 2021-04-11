#include "Coin.hpp"
#include "TransformComponent.hpp"
#include "ComponentManager.hpp"
#include "AnimationComponent.hpp"
#include "ColliderComponent.hpp"

Coin& Coin::onCollision(Entity& e)
{
    if (e.tag == "alien")
    {
        entity.lock()->destroy();
    }

    return *this;
}

Entity& Coin::create(ComponentManager& manager, const SDL_Rect& destRect)
{
	auto& coin = manager.add_entity("coin");
	coin.add_component<Coin>();
	coin.add_component<TransformComponent>(destRect);
	coin.add_component<AnimationComponent>("assets/coin-anim.png", SDL_Rect{ 0, 0, 8, 8 })
		.add_animation("turn", { 0, 4, 225 })
		.play("turn");
	coin.add_component<ColliderComponent>();
	coin.add_group(0);

	return coin;
}
