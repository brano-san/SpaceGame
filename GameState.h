#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "State.h"
#include "Ninja.h"
#include "Enemies.h"

class GameState final : public State
{
public:
	explicit GameState(sf::RenderWindow* window);
	~GameState() override;

	void update(const float& time) override;
	void render() override;
private:
	void configureScene()noexcept;
	
	Ninja* _ninja;

	Enemies* _enemies; //312x336
};