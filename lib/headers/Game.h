#ifndef GAME_H
#define GAME_H

#include <queue>
#include <string>

class Game {
public:
	void nextMove(std::string move);
private:
	std::queue<std::string> history;
};

#endif // !GAME_H