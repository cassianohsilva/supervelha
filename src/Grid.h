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

#include <map>

#include <SFML/Graphics.hpp>

struct GridPosition {
	int line;
	int column;
};

class Grid : public sf::Drawable, public sf::Transformable, public IClickListener, private sf::NonCopyable {
public:
	Grid(uint gridSize, const sf::Vector2f& size);
	virtual ~Grid();

	virtual bool onClickListener(const sf::Vector2f& position, Player* player);

	const sf::Vector2f& getSize() const { return mSize; }

	const Player* getWinner() const { return mWinner; }
	bool hasWinner() const;

	bool isDraw() const { return mIsDraw; }

private:
	void generate();
	void reset();

	bool checkWinner(const GridPosition& lastMove);

	GridPosition getGridPosition(const sf::Vector2f& position);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool verificarLimite(int linha, int coluna) const;

//	GridPosition mLastMove;

	static int vectors[4][2];

	int mWidth;
	int mHeight;
	int mMoves;

	bool mIsDraw;

	sf::Vector2f mSize;

	Square *** mGrid;

	Player* mWinner;
};

#endif /* GRID_H_ */
