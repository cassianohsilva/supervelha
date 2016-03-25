/*
 * Game.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Game.h"

Game::Game() :
		window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SuperVelha"), mGrid(
				8, sf::Vector2f(200.0f, 200.0f)) {

}

Game::~Game() {

}

void Game::run() {
	while (window.isOpen()) {
		sf::Event event;

		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(0xFF, 0xFF, 0xFF));
		window.draw(mGrid);
		window.display();
	}
}
