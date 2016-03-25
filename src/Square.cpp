/*
 * Square.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Square.h"

Square::Square(const sf::Vector2f& size) : mSize(size) {
	mShape.setFillColor(sf::Color(0, 0xFF, 0));
	mShape.setSize(size);
}

Square::~Square() {

}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();

	target.draw(mShape, states);
}
