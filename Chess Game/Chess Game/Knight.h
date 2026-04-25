#ifndef KNIGHT-H
#define KNIGHT-H
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2);
};

#endif