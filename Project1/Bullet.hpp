#include "Component.hpp"
#include "TransformComponent.hpp"

class Bullet : public Component
{
public:
	Bullet& init() override;
	Bullet& update() override;
	static Entity& create(Scene& scene, const SDL_Rect& destRect);
private:
	std::shared_ptr<TransformComponent> transform;
};

