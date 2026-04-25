#ifndef PAWN-H
#define PAWN-H
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2) override;
};

#endif