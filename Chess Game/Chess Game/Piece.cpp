#include "Piece.h"

Piece::Piece(bool isWhite)
{
	this->isWhite = isWhite;
}

char Piece::getSymbol()
{
	return symbol;
}

bool Piece::getColor()
{
	return isWhite;
}