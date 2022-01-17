#include <vector>
#include "Knight.h"
#include "../square/Square.h"

std::vector<Square> Knight::directions = {
  {-2, -1},
  {-2, 1},
  {-1, -2},
  {-1, 2},
  {1, -2},
  {1, 2},
  {2, -1},
  {2, 1},
};

std::vector<Square> Knight::getDirections(Board* board, const Square& sourcePosition) const {
    std::vector<Square> res{};
    for (Square direction : directions) {
        Square targetPosition = sourcePosition + direction;
        // Se la cella è valida e vuota allora posso muovermi
        if (board->isValidSquare(targetPosition) && board->getSquarePiece(targetPosition) == nullptr) {
            res.push_back(targetPosition);
        }
    }


    return res;
}
