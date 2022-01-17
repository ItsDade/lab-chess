#include <vector>
#include "../piece/Bishop.h"
#include "../square/Square.h"

std::vector<Square> Bishop::directions = {
  {-1, -1},
  {-1, 1},
  {1, -1},
  {1, 1},
};

std::vector<Square> Bishop::getDirections(Board* board, const  Square& sourcePosition) const {
	return directions;
}
