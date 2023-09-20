#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window), _ninja(new Ninja("src/sprites/ninja.png")),
	_enemies(new Enemies("src/sprites/asteroid.png", 20, _ninja))
{
	configureScene();
}

GameState::~GameState()
{
	delete this->_ninja;
}

void GameState::update(const float& time)
{
	_ninja->update(time);

	_enemies->update(time);
}

void GameState::render()
{
	_ninja->render(*this->_window);
	_enemies->render(*this->_window);
}

void GameState::configureScene() noexcept
{
	_ninja->setPosition(sf::Vector2f(600, 560));
	_ninja->setScale(sf::Vector2f(0.3f, 0.3f));
}
