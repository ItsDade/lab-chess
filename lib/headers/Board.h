// Include guards
#ifndef BOARD_H
#define BOARD_H

// Include files
#include "Color.h"
#include "Piece.h"
#include "Pedone.h"
#include "Alfiere.h"
#include "Cavallo.h"
#include "Re.h"
#include "Regina.h"
#include "Torre.h"
#include "Empty.h"

#include <vector>
#include <memory>
#include <string>
#include <algorithm>


// Class header
class Board {
	public:
		Board();
		std::string toString();
		void move(char y1, int x1, char y2, int x2);
	private:
		std::vector<std::unique_ptr<Piece>> board;
		Piece* getPiece(char y, int x);
		void swapPieces(Piece* p1, Piece* p2);

		class NotValidMoveExcpetion {};
};
#endif // !BOARD_H