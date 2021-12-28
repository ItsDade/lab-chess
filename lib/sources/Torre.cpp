#include "Torre.h"

Torre::Torre(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Torre::toString() {
	if (color == Color::Black)
		return "T";
	else
		return "t";
}

bool Torre::isValidMove(char y, int x) {
	return false;
}
