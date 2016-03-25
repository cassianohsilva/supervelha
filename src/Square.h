/*
 * Square.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include <SFML/Graphics.hpp>

class Square : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
public:
	Square(const sf::Vector2f& size);
	virtual ~Square();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f mSize;
	sf::RectangleShape mShape;
};

#endif /* SQUARE_H_ */
