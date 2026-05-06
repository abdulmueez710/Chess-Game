#include "Rook.h"
#include "Board.h"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
	symbol = isWhite ? 'R' : 'r';
}

bool Rook::isValidMove(int x1, int y1, int x2, int y2, Board* board)
{

	// Movement logic for Rook
	int rowDiff = (x2 - x1) < 0 ? x1 - x2 : x2 - x1;
	int colDiff = (y2 - y1) < 0 ? y1 - y2 : y2 - y1;

	if (rowDiff != 0 && colDiff != 0)
	{
		return false; // Not a + move
	}

	int xDirection;
	int yDirection;
	if (rowDiff == 0) {
		yDirection = (y2 - y1) > 0 ? 1 : -1;
		xDirection = 0;
	}
	else {
		xDirection = (x2 - x1) > 0 ? 1 : -1;
		yDirection = 0;
	}

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

