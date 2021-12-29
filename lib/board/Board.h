#ifndef BOARD_H
#define BOARD_H

#include "../pieces/Piece.h"
#include <vector>
#include <memory>
#include <string>
#include <sstream>

#include "../pieces/Pawn.h"
#include "../Color/Color.h"


class Board {
	public:
		// Variables

		// Functions
		Board();
		std::string toString() const;

	private:
		// Variables
		std::vector<std::unique_ptr<Piece>> board;

		// Functions
		Piece* getPiece(char y, int x) const;


	friend std::ostream& operator<<(std::ostream& os, const Board& dt);
};


#endif // !BOARD_H
