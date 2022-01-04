#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

// Includes
#include "../Colors.h"
#include "Square.h"

#include "../pieces/Pawn.h"
#include "../pieces/Rook.h"
#include "../pieces/Knight.h"
#include "../pieces/King.h"
#include "../pieces/Queen.h"
#include "../pieces/Bishop.h"


using namespace std;
class Board{
	public:
		// Constructors
		Board();

		// Destructors
		~Board();

		// Functions
		Square* getSquare(char x, int y);
		string toString();

	private:
		vector<Square*> board;

};

#endif // !BOARD_H

