#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum class Color {
	WHITE,
	BLACK,
	NONE
};

/**
* Operatore insert formatted output, utilizzato per stampare il colore.
*
* @param os Output stream.
* @return board Colore.
*/
std::ostream& operator<<(std::ostream& os, const Color& color);

#endif // COLOR_H
