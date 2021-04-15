#include "VisibleComponent.hpp"
#include "TextureManager.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"
#include <string>

VisibleComponent& VisibleComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>();
	orientation = transform->orientation;

	return *this;
}

VisibleComponent& VisibleComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect, orientation);

	return *this;
}

VisibleComponent& VisibleComponent::play(const std::string& str)
{
	return *this;
}
