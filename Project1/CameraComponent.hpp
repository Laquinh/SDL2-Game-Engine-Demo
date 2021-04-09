#ifndef CAMERACOMPONENT_HPP
#define CAMERACOMPONENT_HPP

#include "SDL.h"
#include "Component.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"
#include <memory>

class CameraComponent : public Component, public std::enable_shared_from_this<CameraComponent>
{
public:
	CameraComponent() = default;
	CameraComponent(const std::shared_ptr<TransformComponent>& target, const SDL_Rect& rect);
	CameraComponent(const Entity& entity, const SDL_Rect& rect);
	CameraComponent(const CameraComponent&) = default;
	~CameraComponent() = default;

	CameraComponent& init() override;
	CameraComponent& update() override;

	SDL_Rect rect;
private:
	std::shared_ptr<TransformComponent> target;
	int wi = 1280;
};

#endif