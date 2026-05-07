#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2, Board *board) override;
};

#endif
