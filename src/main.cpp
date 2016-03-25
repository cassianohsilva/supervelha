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

#include "Game.h"

int main(void) {

	Game* game = new Game();

	game->run();

	return EXIT_SUCCESS;
}
