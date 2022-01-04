#include "Square.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructor
Square::Square(Piece* p, char row, int column) {
	setPiece(p);
	setX(row);
	setY(column);
}

// Destructor
Square::~Square() {
	delete piece;
}

// Getter
Piece* Square::getPiece() {
	return piece;
}

char Square::getX() {
	return x;
}

int Square::getY() {
	return y;
}


// Setter
void Square::setPiece(Piece* p) {
	piece = p;
}

void Square::setX(char row) {

	if (row < 'a' || row > 'h')
		throw InvalidPositionExcpetion();

	x = row;
}

void Square::setY(int column) {

	if (column < 1 || column > 8)
		throw InvalidPositionExcpetion();

	y = column;
}