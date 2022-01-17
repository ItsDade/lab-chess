#include "Player.h"
Player::Player(Color c, Game* g){
	color = c;
	game = g;
}

Color Player::getColor(){
	return color;
}
