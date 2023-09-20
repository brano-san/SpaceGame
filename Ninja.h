#pragma once
#include "Entity.h"
#include "Animation.h"

class Ninja final : public Entity
{
public:
	explicit Ninja(const sf::String& path);
	~Ninja() override;

	void update(const float& time) override;
	void render(sf::RenderWindow& window) override;
	void move(const sf::Vector2f& offset);
	void setPosition(const sf::Vector2f& pos);
	void setScale(const sf::Vector2f& scale);
	const sf::IntRect& getRect()const;
	void hit();
private:
	void updateInput()noexcept;
	void checkCollisions(const float& time)noexcept;

	float _vX, _vY;
	bool _isOnGround;
	Animation* _animation;
};