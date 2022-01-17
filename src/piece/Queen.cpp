#include <vector>
#include "../board/Board.h"
#include "../square/Square.h"
#include "../piece/Queen.h"

std::vector<Square> Queen::getDirections(Board* board, const Square& sourcePosition) const {

	// La donna non è altro che una torre e un alfiere combinati

	std::vector<Square> rookMoves = Rook::getDirections(board, sourcePosition);
	std::vector<Square> bishopMoves = Bishop::getDirections(board, sourcePosition);
	rookMoves.insert(rookMoves.end(), bishopMoves.begin(), bishopMoves.end());


	return rookMoves;
}
