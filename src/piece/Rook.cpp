#include <vector>
#include "../square/Square.h"
#include "Rook.h"

std::vector<Square> Rook::directions = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0},
};

std::vector<Square> Rook::getDirections(Board* board, const Square& sourcePosition) const {
	return directions;
}
