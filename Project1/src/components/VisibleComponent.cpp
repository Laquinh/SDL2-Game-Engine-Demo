#include "VisibleComponent.hpp"
#include "../interfaces/AssetManager.hpp"
#include "../Entity.hpp"
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
	AssetManager::draw(*texture, srcRect, destRect, 0);

	return *this;
}

VisibleComponent& VisibleComponent::play(const std::string& str)
{
	return *this;
}
