#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State() = delete;
	explicit State(sf::RenderWindow* window);
	virtual ~State();

	virtual void update(const float& time) = 0;
	virtual void render() = 0;
protected:
	sf::RenderWindow* _window;
};