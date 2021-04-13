#include "AnimationComponent.hpp"
#include "TextureManager.hpp"

AnimationComponent::AnimationComponent(const std::string& path, const Rectangle& srcRect = Rectangle(0, 0, 16, 16))
{
	texture = TextureManager::load_texture(path);
	this->srcRect = srcRect;
}

AnimationComponent& AnimationComponent::update()
{
	srcRect.x = srcRect.width * static_cast<int>((SDL_GetTicks() / speed) % frames);
	srcRect.y = animationIndex * srcRect.height;

	destRect = transform->get_rect();

	return *this;
}

AnimationComponent& AnimationComponent::play(const std::string& str)
{
	frames = animations[str].frames;
	animationIndex = animations[str].index;
	speed = animations[str].speed;

	return *this;
}

AnimationComponent& AnimationComponent::add_animation(const std::string& str, const Animation& anim)
{
	animations.emplace(str, anim);

	return *this;
}
