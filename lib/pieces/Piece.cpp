#include "Piece.h"

Piece::Piece(char c, int r, Color co){

	// Char to lower
	if (c >= 'A' && c <= 'Z')
		c = c - 'A';

	// Check if position is correct
	if (c < 'a' || c > 'z' || r < 1 || r > 8 || co == Color::None)
		throw InvalidPiecePositionExcpetion();

	column = c;
	row = r;
	color = co;
}

char Piece::getColumn(){
	return column;
}

int Piece::getRow(){
	return row;
}
