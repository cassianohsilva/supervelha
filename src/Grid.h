/*
 * Grid.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef GRID_H_
#define GRID_H_

#include "Square.h"

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable, public sf::Transformable, private sf::NonCopyable  {
public:
	Grid(uint gridSize, const sf::Vector2f& size);
	virtual ~Grid();

private:
	void generate();
	void reset();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	uint mWidth;
	uint mHeight;

	sf::Vector2f mSize;

	Square *** mGrid;
};

#endif /* GRID_H_ */
