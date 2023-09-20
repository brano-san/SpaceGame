#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "State.h"
#include "GameState.h"

class Game final
{
public:
    explicit Game()noexcept;
	Game(Game&& game) noexcept;
	Game(const Game&) = delete;
	Game(const sf::VideoMode&, const sf::String&)noexcept;
	~Game()noexcept;

	Game& operator=(Game&) = delete;
	Game& operator=(Game&&) = delete;

	int start();
private:
	sf::RenderWindow* _window;
	sf::Event* _event;
	sf::Clock* _clock;

	float _time{};

	std::stack<State*> _states;

	void update();
	void render();

	void updateEvent()noexcept;
	void updateTime()noexcept;
};
