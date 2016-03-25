/*
 * Grid.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Grid.h"

Grid::Grid(uint gridSize, const sf::Vector2f& size) :
		mWidth(gridSize), mHeight(gridSize), mSize(size), mGrid(nullptr) {
	generate();
}

Grid::~Grid() {
	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			delete mGrid[i][j];
		}
		delete [] mGrid[i];
	}
	delete [] mGrid;
}

void Grid::generate() {
	sf::Vector2f squareSize = mSize / (float) mHeight;

	mGrid = new Square**[mHeight];

	for (int i = 0; i < mHeight; ++i) {
		mGrid[i] = new Square*[mWidth];

		for (int j = 0; j < mWidth; ++j) {
			Square* sq = new Square(squareSize);
			sq->setPosition(i * squareSize.y * 1.1, j * squareSize.x * 1.1);

			mGrid[i][j] = sq;
		}
	}
}

void Grid::reset() {
	// TODO Implementar este método
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();

	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			target.draw(*mGrid[i][j], states);
		}
	}
}
