#include <iostream>
#include "color.h"

std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << (color == Color::WHITE ? "BIANCO" : "NERO");
  return os;
}
