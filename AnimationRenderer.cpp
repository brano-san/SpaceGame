#include "AnimationRenderer.h"

AnimationRenderer::AnimationRenderer(sf::Texture& texture)
	: _texture(new sf::Texture()),
	_sprite(new sf::Sprite())
{
	_texture = &texture;
	_sprite->setTexture(*_texture);
}

AnimationRenderer::~AnimationRenderer()
{
	delete _sprite;
	delete _texture;
}

void AnimationRenderer::move(const sf::Vector2f& offset)
{
	_sprite->move(offset);
}

void AnimationRenderer::setPosition(const sf::Vector2f& pos)
{
	_sprite->setPosition(pos);
}

void AnimationRenderer::setScale(const sf::Vector2f& scale)
{
	_sprite->setScale(scale);
}

void AnimationRenderer::setOrigin(const sf::Vector2f& origin)
{
	_sprite->setOrigin(origin);
}

const sf::Vector2f& AnimationRenderer::getPosition() const
{
	return _sprite->getPosition();
}

void AnimationRenderer::draw(sf::RenderWindow& window, const sf::IntRect& rect)
{
	_sprite->setTextureRect(rect);
	window.draw(*_sprite);
}