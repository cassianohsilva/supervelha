/*
 * Square.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Square.h"

Square::Square(const sf::Vector2f& size) :
		mPlayer(nullptr), mSize(size) {
	mShape.setFillColor(sf::Color(0, 0xFF, 0));
	mShape.setSize(size);

	if (mFont.loadFromFile("res/EricaOne-Regular.ttf")) {
		mText.setFillColor(sf::Color::Black);
		mText.setCharacterSize((uint) (mSize.y * 0.75f));
	}
}

Square::~Square() {

}

bool Square::place(Player* player) {
	if (!mPlayer) {
		mPlayer = player;

		mText.setFont(mFont);
		mText.setString(PlayerTypeToString(player->getType()));

		sf::FloatRect rect = mText.getLocalBounds();

		//printf("(%f, %f, %f, %f)\n", rect.left, rect.top, rect.width, rect.height);

		mText.setPosition((getSize().x - (rect.width + 2 * rect.left)) / 2,
				(getSize().y - (rect.height + 2 * rect.top)) / 2);

		return true;
	}

	return false;
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();

	target.draw(mShape, states);
	if (mPlayer != nullptr) {
		target.draw(mText, states);
	}
}
