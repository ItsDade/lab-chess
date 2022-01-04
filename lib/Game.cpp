#include "Game.h"

Game::Game(Player p1, Player p2){
	players[0] = p1;
	players[1] = p2;

    stillGoing = true;

	board = new Board();

	if (p1.isWhite())
		curr = p1;
	else
		curr = p2;

}

Game::~Game(){
	delete board;
}

bool Game::isEnd(){
    return !stillGoing;
}


bool Game::playerMove(Player* player, char x1, int y1, char x2, int y2){
    Square* startBox = board->getSquare(x1, y1);
    Square* endBox = board->getSquare(x2, y2);
    Move move = Move(player, startBox, endBox);
    return makeMove(move, player);
}

bool Game::makeMove(Move move, Player* player)
{
    Piece* sourcePiece = move.getFrom()->getPiece();
    if (sourcePiece == nullptr)
        return false;
    return true;
}