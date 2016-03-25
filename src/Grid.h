/*
 * Grid.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef GRID_H_
#define GRID_H_

#include "Square.h"
#include "Listener.h"

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable, public sf::Transformable, public IClickListener, private sf::NonCopyable {
public:
	Grid(uint gridSize, const sf::Vector2f& size);
	virtual ~Grid();

	virtual bool onClickListener(const sf::Vector2f& position);

	const sf::Vector2f& getSize() const { return mSize; }

private:
	void generate();
	void reset();

	const Square* getSquareAtPosition(const sf::Vector2f& position) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int mWidth;
	int mHeight;

	sf::Vector2f mSize;

	Square *** mGrid;
};

#endif /* GRID_H_ */
