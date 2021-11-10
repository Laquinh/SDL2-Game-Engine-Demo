#include "Coin.hpp"
#include "TransformComponent.hpp"
#include "AnimationComponent.hpp"
#include "ColliderComponent.hpp"
#include "Player.hpp"
#include "../Scene.hpp"
#include "../Rectangle.hpp"
#include "../Entity.hpp"

Coin& Coin::onCollision(Entity& e)
{
    if (e.tag == "player")
    {
		++e.get_component<Player>()->money;
        entity.lock()->destroy();
    }

    return *this;
}

Entity& Coin::create(Scene& scene, const Rectangle& destRect)
{
	auto& coin = scene.add_entity("coin");
	coin.add_component<Coin>();
	coin.add_component<TransformComponent>(destRect);
	coin.add_component<AnimationComponent>("assets/coin-anim.png", Rectangle( 0, 0, 8, 8 ))
		->add_animation("turn", { 0, 4, 150 })
		.play("turn");
	coin.add_component<ColliderComponent>();
	coin.add_group(0);

	return coin;
}
