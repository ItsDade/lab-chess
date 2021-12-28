#include "Piece.h"

Piece::Piece(char y, int x, Color co){
	row = x;
	column = y;
	color = co;
}

int Piece::getRow()
{
	return row;
}

char Piece::getColumn()
{
	return column;
}

void Piece::setRow(int x){
	row = x;
}

void Piece::setColumn(char y){
	column = y;
}
