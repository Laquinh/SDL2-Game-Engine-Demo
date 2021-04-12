#include "Component.hpp"
#include "TransformComponent.hpp"
#include "Player.hpp"

class Bullet : public Component
{
public:
	Bullet& init() override;
	Bullet& update() override;
	Bullet& onCollision(Entity& e) override;
	static Entity& create(Scene& scene, const SDL_Rect& destRect);
private:
	std::shared_ptr<TransformComponent> transform;
	std::weak_ptr<Player> player;
};