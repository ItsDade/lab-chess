#include "Bishop.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
Bishop::Bishop(Color c) : Piece(c) {}

// Functions
bool Bishop::canMove(Board* b, Square* i, Square* f) {
	return false;
}

std::string Bishop::toString(){
	if (color == Color::White)
		return "a";
	else
		return "A";
}



