#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "ComponentManager.hpp"

class PositionComponent : public Component
{
public:
	~PositionComponent();
	int get_x();
	int get_y();

	void init() override;
	void update() override;
	void draw() override;
	void setPos(int, int);
private:
	int x, y;
};

#endif