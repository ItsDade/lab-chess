#include "Board.h"

std::ostream& operator<<(std::ostream& os, const Board& b){
	return os << b.toString();
}

Board::Board(){
	for (char i = 'a'; i <= 'h'; i++)
		board.emplace_back(new Pawn{i, 2, Color::Black});
}

std::string Board::toString() const {
	std::string res = "";
	for (int i = 0; i < 8; i++) {
		for (int j = 'a'; j <= 'h'; j++) {
			Piece* p = getPiece(j, i);
			if (p != nullptr)
				res = res + p->toString();
			else
				res = res + " ";
		}
		res = res + "\n";
	}
	return res;
}

Piece* Board::getPiece(char y, int x) const {
	for each (auto const& p in board)
			if (p.get()->getColumn() == y && p.get()->getRow() == x)
				return p.get();
	return nullptr;
}
