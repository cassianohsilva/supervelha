/*
 * Game.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Game.h"

Game::Game() :
		window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SuperVelha"), mGrid(8, sf::Vector2f(400.0f, 400.0f)), mPlayer1(
				new Player("p1", PlayerType::X)), mPlayer2(
				new Player("p2", PlayerType::O)), mPlayers{mPlayer1, mPlayer2}, mCurrentPlayer(
						0) {

}

Game::~Game() {

}

void Game::run() {
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					bool click = mGrid.onClickListener(
							sf::Vector2f(event.mouseButton.x,
									event.mouseButton.y), mPlayers[mCurrentPlayer]);

					if(click) {
						changePlayer();
					}
				}
			}
		}

		window.clear(sf::Color(0xFF, 0xFF, 0xFF));
		window.draw(mGrid);
		window.display();
	}
}

void Game::changePlayer() {
	mCurrentPlayer = ++mCurrentPlayer % 2;
}
