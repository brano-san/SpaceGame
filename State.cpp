#include "State.h"

State::State(sf::RenderWindow* window)
	: _window(window)
{
}

State::~State()
{
	this->_window = nullptr;
}
