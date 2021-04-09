#ifndef ANIMATION_HPP
#define ANIMATION_HPP

struct Animation
{
	int index;
	int frames;
	int speed;

	Animation() = default;
	Animation(int index, int frames, int speed);
};

#endif