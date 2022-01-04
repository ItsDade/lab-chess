#ifndef PIECE_H
#define PIECE_H

// Includes
#include "../Colors.h"
#include <string>

class Board;
class Square;

class Piece {
	public:
		// Constructor
		Piece(Color c);

		// Getter
		bool isAlive();
		Color getColor();

		// Setter
		void setAlive(bool a);

		// Functions
		virtual bool canMove(Board* b, Square* i, Square* f) = 0;
		virtual std::string toString() = 0;

	protected:
		bool alive;
		Color color;

};

#endif // !PIECE_H