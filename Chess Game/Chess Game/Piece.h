#ifndef PIECE-H
#define PIECE-H

class Piece {
protected:
    bool isWhite;
    char symbol;

public:
    Piece(bool isWhite);
    virtual bool isValidMove(int x1, int y1, int x2, int y2) = 0;
    char getSymbol();
    bool getColor();
};

#endif