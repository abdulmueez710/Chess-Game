#include "Queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite) {
  isWhite ? 'Q' : 'q';
}

bool Queen::isValidMove(int x1, int y1, int x2, int y2)
{
	// Movment Logic here
}
