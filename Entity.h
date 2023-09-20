#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update(const float& time) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
protected:
	sf::Shape* _hitbox;
};