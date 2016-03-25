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
	Player(const std::string& name, PlayerType type);
	virtual ~Player();

	const std::string& getName() const { return mName; }

	const PlayerType getType() const {
		return mType;
	}

private:
	std::string mName;
	PlayerType mType;
};

#endif /* PLAYER_H_ */
