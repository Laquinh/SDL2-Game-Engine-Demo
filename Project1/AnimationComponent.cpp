#include "AnimationComponent.hpp"
#include "TextureManager.hpp"

AnimationComponent::AnimationComponent(const std::string& path, const SDL_Rect& pSrcRect = SDL_Rect{ 0,0,16,16 })
{
	texture = TextureManager::load_texture(path);
	srcRect = pSrcRect;

	Animation idle = Animation(0, 4, 225);
	Animation walk = Animation(1, 4, 100);

	animations.emplace("Idle", idle);
	animations.emplace("Walk", walk);

	play("Idle");
}

AnimationComponent& AnimationComponent::update()
{
	srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	srcRect.y = animationIndex * srcRect.h;

	destRect = transform->rect;

	return *this;
}

AnimationComponent& AnimationComponent::play(const std::string& str)
{
	frames = animations[str].frames;
	animationIndex = animations[str].index;
	speed = animations[str].speed;

	return *this;
}
