#include "CameraComponent.hpp"
#include "Game.hpp"
#include <iostream>

CameraComponent::CameraComponent(const std::shared_ptr<TransformComponent>& target, const SDL_Rect& rect):
	target(target),
	rect(rect)
{
}

CameraComponent::CameraComponent(const Entity& entity, const SDL_Rect& rect):
	target(entity.get_component<TransformComponent>().shared_from_this()),
	rect(rect)
{
}

CameraComponent& CameraComponent::init()
{
	entity.lock()->add_group(4);
	return *this;
}

CameraComponent& CameraComponent::update()
{
	rect.x = target->rect.x - rect.w / 2 + 48;
	rect.y = target->rect.y - rect.h / 2 + 48;

	if (rect.x < 0)
	{
		rect.x = 0;
	}
	else if (rect.x + rect.w > wi)
	{
		rect.x = wi - rect.w;
	}
	if (rect.y < 0)
	{
		rect.y = 0;
	}
	else if (rect.y + rect.h > wi)
	{
		rect.y = wi - rect.h;
	}

	return *this;
}
