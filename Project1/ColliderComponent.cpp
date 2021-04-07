#include "ColliderComponent.hpp"

#include "Game.hpp"

ColliderComponent::ColliderComponent()
{
}

ColliderComponent::ColliderComponent(const std::string& tag):
	tag(tag)
{
}

ColliderComponent& ColliderComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	collider = transform->rect;

	Game::colliders.emplace_back(shared_from_this());

	return *this;
}

ColliderComponent& ColliderComponent::update()
{
	collider = transform->rect;

	return *this;
}