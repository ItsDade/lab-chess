#include "../headers/Re.h"

Re::Re(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Re::toString() {
	if (color == Color::Black)
		return "R";
	else
		return "r";
}

bool Re::isValidMove(char y, int x) {
	return false;
}
