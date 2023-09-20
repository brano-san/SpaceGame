#include "Enemies.h"

Enemies::Enemies(const sf::String& path, int countEnemies, Ninja* ninja)
	: _dx(0), _dy(0.3), _ninja(ninja)
{
	static sf::Texture texture;
	texture.loadFromFile(path);

	for (int i = 0; i < countEnemies; i++)
	{
		_animations.push_back(new Animation(130, texture));
		_animations[i]->addAnim(AnimState::Idle, sf::IntRect(0, 0, 312, 336), 1);
		_animations[i]->setState(AnimState::Idle);
		_animations[i]->setScale(sf::Vector2f(0.1, 0.1));
		restart(_animations[i]);
	}
}

Enemies::~Enemies()
{
	for (auto& animation : _animations)
	{
		delete animation;
	}
}

void Enemies::update(const float& time)
{
	for (auto& animation : _animations)
	{
		animation->move(sf::Vector2f(_dx, _dy * time));
		animation->update(time);
	}
	checkCollisions();
}

void Enemies::render(sf::RenderWindow& window)
{
	for (auto& animation : _animations)
	{
		animation->render(window);
	}
}

void Enemies::restart(Animation* anim)
{
	anim->setPosition(sf::Vector2f(rand() % 1170, -rand() % 690));
}

void Enemies::checkCollisions()
{
	for (auto& animation : _animations)
	{
		if (animation->getPosition().y > 690)
		{
			restart(animation);
		}
		if (animation->getRect().intersects(_ninja->getRect()))
		{
			_ninja->hit();
		}
	}
}
