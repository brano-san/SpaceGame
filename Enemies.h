#pragma once
#include "Entity.h"
#include "Ninja.h"
#include "Animation.h"

class Enemies final : public Entity
{
public:
	Enemies(const sf::String& path, int countEnemies, Ninja* ninja);
	virtual ~Enemies();

	void update(const float& time)override;
	void render(sf::RenderWindow& window)override;
private:
	void restart(Animation* anim);
	void checkCollisions();

	float _dx{}, _dy{};

	std::vector<Animation*> _animations;

	Ninja* _ninja;
};