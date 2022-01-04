#include <iostream>
#include "../../lib/board/Board.h"

int main() {
	
	Board b{};

	std::cout << b.toString();
	return 0;
}