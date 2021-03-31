#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "ComponentManager.hpp"

class PositionComponent : public Component, public std::enable_shared_from_this<PositionComponent>
{
public:
	PositionComponent();
	PositionComponent(int, int);
	~PositionComponent() override;
	int get_x();
	int get_y();

	void init() override;
	void update() override;
	void draw() override;
	void setPos(int, int);

	std::shared_ptr<PositionComponent> get_ptr();
private:
	int x, y;
};

#endif