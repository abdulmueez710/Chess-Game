#ifndef KING-H
#define KING-H
#include "Piece.h"

class King : public Piece {
public:
    King(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2);
};

#endif