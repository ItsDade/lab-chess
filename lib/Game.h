
#ifndef GAME_H
#define GAME_H

#include "players/Player.h"
#include "board/Board.h"
#include "moves/Move.h"

class Game{
	public:
		Game(Player p1, Player p2);
		~Game();

		bool isEnd();
		bool playerMove(Player* player, char x1, int y1, char x2, int y2);
		bool makeMove(Move move, Player* player);

	private:
		Player players[2];
		Board* board;
		Player curr;
		std::vector<Move> history;
		bool stillGoing;
		

};

#endif // !GAME_H

