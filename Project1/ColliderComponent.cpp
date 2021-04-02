#include "ColliderComponent.hpp"

ColliderComponent& ColliderComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>().get_ptr();

	return *this;
}

ColliderComponent& ColliderComponent::update()
{
	collider = transform->rect;

	return *this;
}