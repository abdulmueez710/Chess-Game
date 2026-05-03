#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) 
{
	symbol = isWhite ? 'B' : 'b';
}

bool Bishop::isValidMove(int x1, int y1, int x2, int y2, Board* board)
{

	// Movement logic for Bishop
	if (((x2 - x1) < 0 ? x1 - x2 : x2 - x1)
		!= ((y2 - y1) < 0 ? y1 - y2 : y2 - y1)) // Make sure the difference is positive for both x and y, and they are equal
	{
		return false; // Not a diagonal move
	}

	int xDirection = (x2 - x1) > 0 ? 1 : -1;
	int yDirection = (y2 - y1) > 0 ? 1 : -1;

	int x = x1 + xDirection;
	int y = y1 + yDirection;

	while (x != x2 || y != y2) {
		if (!board->isInside(x, y)) {
			return false; // Safety: out of bounds
		}
		if (board->getPiece(x, y) != nullptr) {
			return false; // Path is blocked
		}
		x += xDirection;
		y += yDirection;
	}

	Piece* target = board->getPiece(x2, y2);
	if (target != nullptr && target->getColor() == isWhite) {
		return false; // Can't capture own piece
	}

	return true;
}
