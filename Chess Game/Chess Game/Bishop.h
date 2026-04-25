#ifndef BISHOP-H
#define BISHOP-H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2);
};

#endif