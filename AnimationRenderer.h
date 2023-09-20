#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationLogic.h"

class AnimationRenderer
{
public:
	explicit AnimationRenderer(sf::Texture& texture);
	~AnimationRenderer();

	void move(const sf::Vector2f& offset);
	void setPosition(const sf::Vector2f& pos);
	void setScale(const sf::Vector2f& scale);
	void setOrigin(const sf::Vector2f& origin);
	const sf::Vector2f& getPosition()const;
protected:
	void draw(sf::RenderWindow& window, const sf::IntRect& rect);

	sf::Texture* _texture;
	sf::Sprite* _sprite;
};