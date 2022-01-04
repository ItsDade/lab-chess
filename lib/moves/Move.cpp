#include "Move.h"
Move::Move(Player* p, Square* i, Square* f){
	player = p;
	initial = i;
	final = f;
}

Player* Move::getPlayer(){
	return player;
}

Square* Move::getFrom(){
	return initial;
}

Square* Move::getTo(){
	return final;
}

void Move::setPlayer(Player* p){
	player = p;
}

void Move::setFrom(Square* i){
	initial = i;
}

void Move::setTo(Square* f){
	final = f;
}
