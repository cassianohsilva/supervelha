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

#include "Grid.h"
#include "Player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class Game {
public:
	Game();
	virtual ~Game();

	void run();

private:
	void changePlayer();

	bool isStarted;
	bool isFinished;

	sf::RenderWindow window;

	Grid mGrid;

	Player* mPlayer1;
	Player* mPlayer2;

	Player * mPlayers[2];

	int mCurrentPlayer;
};

#endif /* GAME_H_ */
