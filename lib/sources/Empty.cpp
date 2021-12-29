#include "../headers/Empty.h"

Empty::Empty(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Empty::toString() {
	return " ";
}

bool Empty::isValidMove(char y, int x) {
	return false;
}
