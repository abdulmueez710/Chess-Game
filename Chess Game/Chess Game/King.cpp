#include "King.h"
#include "Board.h"

King::King(bool isWhite) : Piece(isWhite) { symbol = isWhite ? 'Q' : 'q';}

bool King::isValidMove(int x1, int y1, int x2, int y2)
{
	// Movment Logic here
}
