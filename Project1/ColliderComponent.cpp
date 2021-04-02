#include "ColliderComponent.hpp"

void ColliderComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().get_ptr();
}

void ColliderComponent::update()
{
	collider = transform->rect;
}