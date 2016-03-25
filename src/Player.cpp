/*
 * Player.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Player.h"

#include <stdio.h>

std::string PlayerTypeToString(const PlayerType& type) {
	return type == PlayerType::O ? "O" : "X";
}

Player::Player(PlayerType type) : mType(type) {

}

Player::~Player() {

}

