#include "ColliderComponent.hpp"

#include "Game.hpp"

#include <algorithm>

ColliderComponent::ColliderComponent()
{
}

ColliderComponent::~ColliderComponent()
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

ColliderComponent& ColliderComponent::destroy()
{
	Game::colliders.erase(std::find(Game::colliders.begin(), Game::colliders.end(), shared_from_this()));
	return *this;
}