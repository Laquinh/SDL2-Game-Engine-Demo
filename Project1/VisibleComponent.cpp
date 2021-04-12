#include "VisibleComponent.hpp"
#include "TextureManager.hpp"

VisibleComponent& VisibleComponent::init()
{
	transform = entity.lock()->get_component<TransformComponent>();

	return *this;
}

VisibleComponent& VisibleComponent::draw()
{
	TextureManager::draw(*texture, srcRect, destRect);

	return *this;
}

VisibleComponent& VisibleComponent::play(const std::string& str)
{
	return *this;
}
