#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool isWhite);
    bool isValidMove(int x1, int y1, int x2, int y2, Board* board) override;
};

#endif