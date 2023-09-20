#include "Animation.h"

Animation::Animation(const float& msBetweenFrames, sf::Texture& texture)
	: AnimationLogic(msBetweenFrames),
	AnimationRenderer(texture)
{

}

void Animation::render(sf::RenderWindow& window)
{
	this->draw(window, this->getRect());
}
