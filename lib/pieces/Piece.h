#ifndef PIECE_H
#define PIECE_H

#include "../Color/Color.h"
#include <string>

class Piece {
	public:
		Piece(char c, int r, Color co);
		char getColumn();
		int getRow();
		virtual bool isValidMove(char y, int x) = 0;
		virtual std::string toString() = 0;
	protected:
		char column;
		int row;
		Color color;

		// Errors
		class InvalidPiecePositionExcpetion{};
};

#endif // !PIECE_H
