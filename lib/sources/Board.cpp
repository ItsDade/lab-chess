#include "../headers/Board.h"
#include <iostream>

Board::Board() {
	board.emplace_back(new Torre('a', 8, Color::Black));
	board.emplace_back(new Cavallo('b', 8, Color::Black));
	board.emplace_back(new Alfiere('c', 8, Color::Black));
	board.emplace_back(new Regina('d', 8, Color::Black));
	board.emplace_back(new Re('e', 8, Color::Black));
	board.emplace_back(new Alfiere('f', 8, Color::Black));
	board.emplace_back(new Cavallo('g', 8, Color::Black));
	board.emplace_back(new Torre('h', 8, Color::Black));
	for (int i = 'a'; i <= 'h'; i++)
		board.emplace_back(new Pedone(i, 7, Color::Black));

	for (int j = 6; j >= 3; j--) {
		for (int i = 'a'; i <= 'h'; i++)
			board.emplace_back(new Empty(i, j, Color::Black));
	}


	for (int i = 'a'; i <= 'h'; i++)
		board.emplace_back(new Pedone(i, 2, Color::White));
	board.emplace_back(new Torre('a', 1, Color::White));
	board.emplace_back(new Cavallo('b', 1, Color::White));
	board.emplace_back(new Alfiere('c', 1, Color::White));
	board.emplace_back(new Regina('d', 1, Color::White));
	board.emplace_back(new Re('e', 1, Color::White));
	board.emplace_back(new Alfiere('f', 1, Color::White));
	board.emplace_back(new Cavallo('g', 1, Color::White));
	board.emplace_back(new Torre('h', 1, Color::White));

}

std::string Board::toString(){
	std::string res = "";
	for (int i = 8; i >= 1; i--) {
		res += std::to_string(i) + " ";
		for (char j = 'a'; j <= 'h'; j++) {
			res += (getPiece(j, i)->toString());
		}
		res.append("\n");
	}
	res += "\n  ABCDEFGH\n";
	return res;
}

void Board::move(char y1, int x1, char y2, int x2){
	Piece* p1 = getPiece(y1, x1);
	Piece* target = getPiece(y2, x2);

	if (!p1->isValidMove(y2, x2))
		throw NotValidMoveExcpetion();

	// Movement to a empty spot
	if (dynamic_cast<Empty*>(target) != nullptr)
		swapPieces(p1, target);

	// TODO: Handle En-Passant
	
	// TODO: Handle Castling

	// TODO: Handle "Mangiare"

}

Piece* Board::getPiece(char y, int x){
	if (y >= 65 && y <= 90)
		y += 32; // to lower
	return board[(8-x)*8 + (y - 'a')].get();
}

void Board::swapPieces(Piece* p1, Piece* p2){
	std::swap(board[(8 - p1->getRow()) * 8 + (p1->getColumn() - 'a')], board[(8 - p2->getRow()) * 8 + (p2->getColumn() - 'a')]);
	char tmpCol = p1->getColumn();
	p1->setColumn(p2->getColumn());
	p2->setColumn(tmpCol);

	int tmpRow = p1->getRow();
	p1->setRow(p2->getRow());
	p2->setRow(tmpRow);

}
