#include "Piece.h"

Piece::Piece(bool isWhite)
{
	this->isWhite = isWhite;
	this->symbol = ' '; // Initialize to fix C26495 warning
}

char Piece::getSymbol()
{
	return symbol;
}

bool Piece::getColor()
{
	return isWhite;
}