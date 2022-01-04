#include "Board.h"
#include <iostream>

// Constructors
Board::Board(){

    
    // White team
    board.push_back(new Square(new Rook(Color::White), 'a', 1));
    board.push_back(new Square(new Knight(Color::White), 'b', 1));
    board.push_back(new Square(new Bishop(Color::White), 'c', 1));
    board.push_back(new Square(new Queen(Color::White), 'd', 1));
    board.push_back(new Square(new King(Color::White), 'e', 1));
    board.push_back(new Square(new Bishop(Color::White), 'f', 1));
    board.push_back(new Square(new Knight(Color::White), 'g', 1));
    board.push_back(new Square(new Rook(Color::White), 'h', 1));

    for (int i = 'a'; i <= 'h'; i++)
        board.push_back(new Square(new Pawn(Color::White), i, 2));

    // Black team
    board.push_back(new Square(new Rook(Color::Black), 'a', 8));
    board.push_back(new Square(new Knight(Color::Black), 'b', 8));
    board.push_back(new Square(new Bishop(Color::Black), 'c', 8));
    board.push_back(new Square(new Queen(Color::Black), 'd', 8));
    board.push_back(new Square(new King(Color::Black), 'e', 8));
    board.push_back(new Square(new Bishop(Color::Black), 'f', 8));
    board.push_back(new Square(new Knight(Color::Black), 'g', 8));
    board.push_back(new Square(new Rook(Color::Black), 'h', 8));

    for(int i = 'a'; i <= 'h'; i++)
        board.push_back(new Square(new Pawn(Color::Black), i, 7));



}

// Destructors
Board::~Board(){
    board.clear();
    std::vector<Square*>().swap(board); // Trick to deallocate memory
}

// Functions
Square* Board::getSquare(char x, int y){
    if(x < 'a' || x > 'h' || y < 1 || y > 8)
        throw Square::InvalidPositionExcpetion();
    int index = (8 - y) * 8 + (x - 'a');

    for each (Square* s in board) 
        if (s->getX() == x && s->getY() == y)
            return s;

    return nullptr;
}

string Board::toString() {
    string res = "";
    for (int i = 8; i >= 1; i--) {
        res += to_string(i) + " ";
        for (char j = 'a'; j <= 'h'; j++) {
            Square* ptr = getSquare(j, i);
            if (ptr == nullptr)
                res += " ";
            else
                res += ptr->getPiece()->toString();
        }
        res += "\n";
    }
    res += "\n  ABCDEFGH";
    return res;
}