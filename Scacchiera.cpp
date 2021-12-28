#include <iostream>
#include "lib/Board.h"

int main() {
	Board b{};
	std::cout << b.toString();
	b.move('c', 2, 'c', 3);
	std::cout << b.toString();
	b.move('c', 3, 'c', 4);
	std::cout << b.toString();
	b.move('c', 4, 'c', 7);
	std::cout << b.toString();
	return 0;
}