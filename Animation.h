#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationLogic.h"
#include "AnimationRenderer.h"

class Animation : public AnimationLogic, public AnimationRenderer
{
public:
	Animation(const float& msBetweenFrames, sf::Texture& texture);
	~Animation() = default;

	void render(sf::RenderWindow& window);
};