/*
 * Square.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include <SFML/Graphics.hpp>

#include "Player.h"

class Square : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
public:
	Square(const sf::Vector2f& size);
	virtual ~Square();

	const sf::Vector2f& getSize() const { return mSize; }
	bool place(const Player* player);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	const Player* mPlayer;
	sf::Font mFont;
	sf::Text mText;
	sf::Vector2f mSize;
	sf::RectangleShape mShape;
};

#endif /* SQUARE_H_ */
