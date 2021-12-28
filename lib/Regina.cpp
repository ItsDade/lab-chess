#include "Regina.h"

Regina::Regina(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Regina::toString() {
	if (color == Color::Black)
		return "D";
	else
		return "d";
}

bool Regina::isValidMove(char y, int x) {
	return false;
}
