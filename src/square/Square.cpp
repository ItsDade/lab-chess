#include <cctype>
#include <stdexcept>
#include <string>
#include "Square.h"

Square::Square(std::string input) {
    if (input.length() < 2)
        throw std::runtime_error("Casella inserita non valida.");

    x = tolower(input[0]) - 'a';
    y = input[1] - '1';
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

Square operator+(Square leftOperator, Square rightOperator) {
    return Square(leftOperator.getX() + rightOperator.getX(), rightOperator.getY() + leftOperator.getY());
}

bool operator==(const Square& leftOperator, const Square& rightOperator) {
    return leftOperator.getX() == rightOperator.getX() && leftOperator.getY() == rightOperator.getY();
}

bool operator!=(const Square& leftOperator, const Square& rightOperator) {
    return !(leftOperator == rightOperator);
}
