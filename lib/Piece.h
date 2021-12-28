// Precompiler options
#pragma once

// Include files
#include "Color.h"
#include <string>


// Class header
class Piece {
	public:
		virtual bool isValidMove(char y, int x) = 0;
		virtual std::string toString() = 0;
		Piece(char y, int x, Color co);
		int getRow();
		char getColumn();
		void setRow(int x);
		void setColumn(char y);
	protected:
		int row;
		char column;
		Color color;
};