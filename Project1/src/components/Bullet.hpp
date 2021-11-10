#include "../Component.hpp"
#include "TransformComponent.hpp"

class Player;
class Scene;
class Entity;
struct Rectangle;

class Bullet : public Component
{
public:
	Bullet();
	Bullet& init() override;
	Bullet& update() override;
	Bullet& onCollision(Entity& e) override;
	static Entity& create(Scene& scene, const Rectangle& destRect, TransformComponent::Orientation orientation);
private:
	std::shared_ptr<TransformComponent> transform;
	std::weak_ptr<Player> player;
	int speed;
};