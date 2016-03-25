/*
 * Grid.cpp
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#include "Grid.h"

#include "Utils.h"

#include <stdio.h>
#include <vector>

int Grid::vectors[4][2] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };

Grid::Grid(uint gridSize, const sf::Vector2f& size) :
		mWidth(gridSize), mHeight(gridSize), mMoves(0), mIsDraw(false), mSize(
				size), mGrid(nullptr), mWinner(nullptr) {

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
			mGrid[i][j]->setPosition(j * squareSize.x + 0.05 * squareSize.x,
					i * squareSize.y + 0.05 * squareSize.y);
		}
	}
}

void Grid::reset() {
	// TODO Implementar este método
}

bool Grid::onClickListener(const sf::Vector2f& position, Player* player) {
	GridPosition gridPosition = getGridPosition(position);

	if (gridPosition.line >= 0 && gridPosition.column >= 0) {
		mGrid[gridPosition.line][gridPosition.column]->place(player);

		checkWinner(gridPosition);

		return true;
	}

	return false;
}

GridPosition Grid::getGridPosition(const sf::Vector2f& position) {
	int i = -1, j = -1;

	if (pointInsideRect(sf::FloatRect(getPosition(), getSize()), position)) {
		do {
			++i;
		} while (i + 1 < mHeight
				&& (mGrid[i][0]->getPosition().y + mGrid[i][0]->getSize().y)
						< position.y);

		do {
			++j;
		} while (j + 1 < mWidth
				&& (mGrid[0][j]->getPosition().x + mGrid[0][j]->getSize().x)
						< position.x);
	}

	return {i, j};
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();

	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			target.draw(*mGrid[i][j], states);
		}
	}
}

bool Grid::hasWinner() const {
	return mWinner != nullptr || mIsDraw;
}

bool Grid::verificarLimite(int linha, int coluna) const {
	return linha >= 0 && linha < mHeight && coluna >= 0 && coluna < mWidth;
}

bool Grid::checkWinner(const GridPosition& lastMove) {
	std::vector<Square*> moves;
	moves.reserve(8);

	bool jogoGanho = false;

	for (int i = 0; i < 4; ++i) {
		int vetor[2] = { vectors[i][0], vectors[i][1] };

		int linhaAtual = lastMove.line + vetor[0];
		int colunaAtual = lastMove.column + vetor[1];

		moves.push_back(mGrid[lastMove.line][lastMove.column]);

		while (verificarLimite(linhaAtual, colunaAtual)
				&& mGrid[linhaAtual][colunaAtual]->getPlayer()
						== moves.front()->getPlayer()) {
			moves.push_back(mGrid[linhaAtual][colunaAtual]);

			linhaAtual += vetor[0];
			colunaAtual += vetor[1];
		}

		linhaAtual = lastMove.line - vetor[0];
		colunaAtual = lastMove.column - vetor[1];

		while (verificarLimite(linhaAtual, colunaAtual)
				&& mGrid[linhaAtual][colunaAtual]->getPlayer()
						== moves.front()->getPlayer()) {
			moves.push_back(mGrid[linhaAtual][colunaAtual]);

			linhaAtual -= vetor[0];
			colunaAtual -= vetor[1];
		}

		if (moves.size() >= 5) {
			jogoGanho = true;
			mWinner = moves.front()->getPlayer();
		}

		moves.clear();

		if(jogoGanho) {
			break;
		}
	}

	if (!jogoGanho && (mMoves == mHeight * mWidth)) {
		jogoGanho = true;
		mIsDraw = true;
	}

	return jogoGanho;
}
