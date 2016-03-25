/*
 * Player.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

enum class PlayerType {
	X, O
};

std::string PlayerTypeToString(const PlayerType& type);

class Player {
public:
	Player(PlayerType type);
	virtual ~Player();

	const PlayerType getType() const {
		return mType;
	}

private:
	PlayerType mType;
};

#endif /* PLAYER_H_ */
