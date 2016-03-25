/*
 * Game.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include "Grid.h"

class Game {
public:
	Game();
	virtual ~Game();

	void run();

private:
	sf::RenderWindow window;

	Grid mGrid;
};

#endif /* GAME_H_ */