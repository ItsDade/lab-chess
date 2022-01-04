#ifndef MOVE_H
#define MOVE_H

#include "../players/Player.h"
#include "../board/Square.h"

class Move{
	public:
		Move(Player* p, Square* i, Square* f);

		Player* getPlayer();
		Square* getFrom();
		Square* getTo();

		void setPlayer(Player* p);
		void setFrom(Square* i);
		void setTo(Square* f);

	private:
		Player* player;
		Square* initial;
		Square* final;

};
#endif // !MOVE_H
