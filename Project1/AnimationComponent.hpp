#ifndef ANIMATIONCOMPONENT_HPP
#define ANIMATIONCOMPONENT_HPP

#include <string>
#include <map>

#include "SDL.h"

#include "VisibleComponent.hpp"
#include "TransformComponent.hpp"
#include "Animation.hpp"
#include <memory>
#include <string>

class AnimationComponent : public VisibleComponent, public std::enable_shared_from_this<AnimationComponent>
{
public:
	AnimationComponent();
	AnimationComponent(const std::string& path, const SDL_Rect& rect);

	AnimationComponent& update() override;
	AnimationComponent& play(const std::string& str) override;

private:
	int animationIndex;
	int speed;
	int frames;

	std::map<const std::string, Animation> animations;
};

#endif