#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include <iostream>

using namespace std;

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = nullptr;
    }
  }
}

void Board::initialize() {

  // --- Pawn ---
  for (int j = 0; j < 8; j++) {
    grid[6][j] = new Pawn(true);
    grid[1][j] = new Pawn(false);
  }

  // --- Bishop ---
  for (int j = 0; j < 8; j++) {
    if (j == 2 || j == 5) {
      grid[0][j] = new Bishop(false);
      grid[7][j] = new Bishop(true);
    }
  }

  // ==== King on Board ====
  for(int i = 0; i < 8; i++){
    if(i == 4){
      grid[7][j] = new King(true);
      grid[0][j] = new King(false);
    }
  }
}

void Board::display() {

  // Top border
  for (int k = 0; k < 9; k++) {
    cout << "---+";
  }
  cout << "\n";

  for (int i = 0; i < 9; i++) {
    if (i == 8) {
      cout << "   |";
    } // Print column numbers at the bottom
    else {
      cout << " " << i + 1
           << " |"; // Count rows from 1 to 8 for user-friendly display
    }

    for (int j = 0; j < 8; j++) {
      if (i == 8) {
        cout << " " << j + 1
             << " |"; // Count columns from 1 to 8 for user-friendly display
      } else if (grid[i][j] == nullptr)
        cout << " . |"; // Empty square
      else
        cout << " " << grid[i][j]->getSymbol() << " |"; // Print piece symbol
    }
    cout << endl;

    // Horizontal separator after every row
    for (int k = 0; k < 9; k++)
      cout << "---+";
    cout << "\n";
  }
}

bool Board::movePiece(int x1, int y1, int x2, int y2, bool whiteTurn) {
  if (!isInside(x1, y1) || !isInside(x2, y2)) {
    return false;
  } // Check if coordinates are within the board

  Piece *p = grid[x1][y1];

  if (p == nullptr) {
    return false;
  }

  // Ensure the piece belongs to the current player
  if (p->getColor() != whiteTurn) {
    return false;
  }

  Piece *target = grid[x2][y2];

  // Prevent friendly fire entirely for all pieces
  if (target != nullptr && target->getColor() == p->getColor())
    return false;

  if (!p->isValidMove(x1, y1, x2, y2, this))
    return false;

  // Move piece
  if (target != nullptr) {
    delete target; // Clean up captured memory
  }

  grid[x2][y2] = p;
  grid[x1][y1] = nullptr;

  return true;
}

bool Board::isInside(int x,
                     int y) { // Check if coordinates are within the 8x8 board
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    return true;
  else
    return false;
}

Piece *Board::getPiece(int x, int y) { return grid[x][y]; }
