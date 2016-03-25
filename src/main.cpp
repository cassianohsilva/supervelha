//============================================================================
// Name        : SuperVelha.cpp
// Author      : Cassiano Honorio da Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Grid.h"

int main(void) {

	Grid* g = new Grid(8, sf::Vector2f(200.0f, 200.0f));

	sf::RenderWindow window(sf::VideoMode(800, 600), "SuperVelha");

	while(window.isOpen()) {
		sf::Event event;

		if(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(0xFF, 0xFF, 0xFF));
		window.draw(*g);
		window.display();
	}

	return EXIT_SUCCESS;
}
