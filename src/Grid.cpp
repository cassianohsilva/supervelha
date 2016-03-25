/*
 * Grid.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Grid.h"

#include "Utils.h"

#include <stdio.h>

Grid::Grid(uint gridSize, const sf::Vector2f& size) :
		mWidth(gridSize), mHeight(gridSize), mSize(size), mGrid(nullptr) {
	generate();
}

Grid::~Grid() {
	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			delete mGrid[i][j];
		}
		delete[] mGrid[i];
	}
	delete[] mGrid;
}

void Grid::generate() {
	sf::Vector2f squareSize = mSize / (float) mHeight;
	sf::Vector2f margin = squareSize * 0.1f;

	mGrid = new Square**[mHeight];

	for (int i = 0; i < mHeight; ++i) {
		mGrid[i] = new Square*[mWidth];

		for (int j = 0; j < mWidth; ++j) {
			mGrid[i][j] = new Square(squareSize - margin);
			mGrid[i][j]->setPosition(i * squareSize.y, j * squareSize.x);
		}
	}
}

void Grid::reset() {
	// TODO Implementar este método
}

bool Grid::onClickListener(const sf::Vector2f& position) {
	if (getSquareAtPosition(position)) {
		return true;
	}

	return false;
}

const Square* Grid::getSquareAtPosition(const sf::Vector2f& position) const {
	int i = -1, j = -1;

	if (pointInsideRect(sf::FloatRect(getPosition(), getSize()), position)) {
		do {
			++i;
		} while (i + 1 < mHeight
				&& (mGrid[i + 1][0]->getPosition().y
						+ mGrid[i + 1][0]->getSize().y) < position.y);

		do {
			++j;
		} while (j + 1 < mWidth
				&& (mGrid[0][j + 1]->getPosition().x
						+ mGrid[0][j + 1]->getSize().x) < position.x);
	}

	if (i < 0 || j < 0) {
		return nullptr;
	} else {
		return mGrid[i][j];
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();

	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			target.draw(*mGrid[i][j], states);
		}
	}
}
