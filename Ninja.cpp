#include "Ninja.h"
#include <iostream>

Ninja::Ninja(const sf::String& path)
	: _vX(0), _vY(0),
	_isOnGround(true)
{
	static sf::Texture texture;
	texture.loadFromFile(path);

	_animation = new Animation(100, texture);

	_animation->addAnim(AnimState::Idle, sf::IntRect(0, 0, 232, 439), 9);
	_animation->addAnim(AnimState::Run, sf::IntRect(0, 439, 363, 458), 9);
	_animation->addAnim(AnimState::Jump, sf::IntRect(0, 897, 362, 483), 9);
	_animation->setState(AnimState::Idle);
}

Ninja::~Ninja()
{
	delete _animation;
}

void Ninja::update(const float& time)
{
	this->updateInput();
	this->checkCollisions(time);
	this->_animation->update(time);
	this->move(sf::Vector2f(_vX * time, _vY * time));
}

void Ninja::render(sf::RenderWindow& window)
{
	_animation->render(window);
}

void Ninja::move(const sf::Vector2f& offset)
{
	_animation->move(offset);
}

void Ninja::setPosition(const sf::Vector2f& pos)
{
	_animation->setPosition(pos);
}

void Ninja::setScale(const sf::Vector2f& scale)
{
	_animation->setScale(scale);
}

const sf::IntRect& Ninja::getRect() const
{
	return _animation->getRect();
}

//UNDONE: Сделать функцию удара по игроку
void Ninja::hit()
{

}

void Ninja::updateInput() noexcept
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
	{
		this->_animation->setState(AnimState::Run);

		this->_animation->setOrigin(sf::Vector2f(
			this->_animation->getRect().height, 0));
		this->setScale(sf::Vector2f(-0.3f, 0.3f));

		this->_vX = -0.5;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
	{
		this->_animation->setState(AnimState::Run);

		this->_animation->setOrigin(sf::Vector2f(
			this->_animation->getRect().left, 0));
		this->setScale(sf::Vector2f(0.3f, 0.3f));

		this->_vX = 0.5;
	}
	else //nothing
	{
		this->_vX = 0;
		this->_animation->setState(AnimState::Idle);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _isOnGround)
	{
		_isOnGround = false;
		_vY = -0.5;
	}
}

void Ninja::checkCollisions(const float& time) noexcept
{
	if (!_isOnGround)
	{
		_vY += 0.001f * time;
		this->_animation->setState(AnimState::Jump);
		if (_animation->getPosition().y > 560)
		{
			_animation->setPosition(sf::Vector2f(_animation->getPosition().x, 560));
			_isOnGround = true;
			_vY = 0;
		}
	}
	
	if(_animation->getPosition().x < -30)
	{
		_animation->setPosition(sf::Vector2f(-30, _animation->getPosition().y));
	}
	else if (_animation->getPosition().x > 1135)
	{
		_animation->setPosition(sf::Vector2f(1135, _animation->getPosition().y));
	}
}