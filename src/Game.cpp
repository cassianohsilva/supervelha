/*
 * Game.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Game.h"

Game::Game() :
		window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SuperVelha"), mGrid(
				8, sf::Vector2f(400.0f, 400.0f)), mPlayer1(new Player(PlayerType::X)), mPlayer2(nullptr) {

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

			if(event.type == sf::Event::MouseButtonReleased) {
				if(event.mouseButton.button == sf::Mouse::Left) {
					mGrid.onClickListener(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), mPlayer1);
				}
			}
		}

		window.clear(sf::Color(0xFF, 0xFF, 0xFF));
		window.draw(mGrid);
		window.display();
	}
}
