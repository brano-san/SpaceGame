#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	srand(time(NULL));
	Game game(sf::VideoMode(1240, 690), "Mario!!!");

	return game.start();
}