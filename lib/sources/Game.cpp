#include "../headers/Game.h"

#include <regex>

void Game::nextMove(std::string move) {
	if (std::regex_match(move, std::regex { "/[a - h][1 - 8][a - h][1 - 8]|xx xx/gm)" }))
		return;

}