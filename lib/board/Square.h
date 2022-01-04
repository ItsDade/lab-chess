#ifndef SQUARE_H
#define SQUARE_H

// Includes
#include "../board/Board.h"
class Piece;




class Square {
	public:

		// Constructor
		Square(Piece* p, char row, int column);

		// Destructor
		~Square();

		// Getter
		Piece* getPiece();
		char getX();
		int getY();

		// Setter
		void setPiece(Piece* p);
		void setX(char row);
		void setY(int column);

		// Errors
		class InvalidPositionExcpetion {};

	private:
		Piece* piece;
		char x;
		int y;
};

#endif // !SQUARE_H

