#include "Game.h"
#pragma warning(disable: 26812)

Game::Game()noexcept
	: _window(new sf::RenderWindow()),
	_event(new sf::Event()),
	_clock(new sf::Clock())
{
	_window->setPosition(sf::Vector2i(0, 0));
	_states.push(new GameState(this->_window));
}

Game::Game(Game&& game) noexcept
	: _window(game._window),
	_event(game._event),
	_clock(game._clock)
{
	game._window = nullptr;
	game._event = nullptr;
	game._clock = nullptr;

	_window->setPosition(sf::Vector2i(0, 0));
	_states.push(new GameState(this->_window));
}

Game::Game(const sf::VideoMode& vd, const sf::String& name)noexcept
	: _window(new sf::RenderWindow(vd, name)),
	_event(new sf::Event()),
	_clock(new sf::Clock())
{
	_window->setPosition(sf::Vector2i(0, 0));
	_states.push(new GameState(this->_window));
}

Game::~Game()noexcept
{
	delete this->_event;
	delete this->_clock;
	delete this->_window;
}

int Game::start()
{
	while(this->_window->isOpen())
	{
		this->update();
		this->render();
	}
	return -1;
}

void Game::update()
{
	this->updateEvent();
	this->updateTime();

	if(!_states.empty())
		this->_states.top()->update(this->_time);
}

void Game::render()
{
	this->_window->clear();

	if (!_states.empty())
		this->_states.top()->render();

	this->_window->display();
}

void Game::updateEvent()noexcept
{
	while (this->_window->pollEvent(*this->_event))
	{
		if(this->_event->type == sf::Event::Closed)
		{
			this->_window->close();
		}
	}
}

void Game::updateTime()noexcept
{
	this->_time = static_cast<float>(this->_clock->restart().asMicroseconds()) / 800;
}