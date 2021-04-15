#include "CameraComponent.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Rectangle.hpp"
#include <iostream>
#include "Entity.hpp"
#include "Rectangle.hpp"
#include "Scene.hpp"
#include "TransformComponent.hpp"

CameraComponent::CameraComponent(const std::shared_ptr<TransformComponent>& target, const Rectangle& rect):
	target(target),
	rect(rect)
{
}

CameraComponent::CameraComponent(const Entity& entity, const Rectangle& rect):
	target(entity.get_component<TransformComponent>()),
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
	rect.x = target->get_x() - rect.width / 2 + 48;
	rect.y = target->get_y() - rect.height / 2 + 48;

	if (rect.x < 0)
	{
		rect.x = 0;
	}
	else if (rect.x + rect.width > wi)
	{
		rect.x = wi - rect.width;
	}
	if (rect.y < 0)
	{
		rect.y = 0;
	}
	else if (rect.y + rect.height > wi)
	{
		rect.y = wi - rect.height;
	}

	return *this;
}

Entity& CameraComponent::create(Scene& scene, int width, int height, const Entity& target)
{
	auto& camera = scene.add_entity("camera");

	camera.add_component<CameraComponent>(target.get_component<TransformComponent>(), Rectangle{ 0, 0, width, height });
	TextureManager::init(camera.get_component<CameraComponent>());

	return camera;
}
