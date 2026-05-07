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

  //     Pawn    
  for (int j = 0; j < 8; j++) {
    grid[6][j] = new Pawn(true);
    grid[1][j] = new Pawn(false);
  }

  //     Bishop 
  for (int j = 0; j < 8; j++) {
    if (j == 2 || j == 5) {
      grid[0][j] = new Bishop(false);
      grid[7][j] = new Bishop(true);
    }
  }

  //      King on Board
  for(int i = 0; i < 8; i++){
    if(i == 4){
      grid[7][i] = new King(true);
      grid[0][i] = new King(false);
    }
  }

  //       Queen display on board
  for(int i = 0; i < 8; i++) {
    if(i == 3){
      grid[0][i] = new Queen(false);
      grid[7][i] = new Queen(true);
    }
  }
}

void Board::display() {
    // 1. Column Labels (a b c...) at the TOP (optional, but looks professional)
    cout << "     "; // Offset for row numbers
    for (int j = 0; j < 8; j++) {
        if(j == 0){
          cout << " " << char(j + 97) << " ";
        }
        else{
          cout << "  " << char(j + 97) << " ";
        }
    } 
    cout << "\n";

    for (int i = 0; i < 8; i++) {
        // 2. Top border for the squares ONLY
        cout << "    "; // Offset
        for (int k = 0; k < 8; k++){
          if(k == 0){
            cout << "----+";
          }
          else
            cout << "---+";
        }
        cout << "\n";

        // 3. Row number on the left (No bar before it)
        cout << " " << (8 - i) << "  |"; 

        // 4. The actual pieces/squares
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr)
                cout << " . |";
            else
                cout << " " << grid[i][j]->getSymbol() << " |";
        }
        cout << " " << (8 - i); // Optional: Row number on the right side too
        cout << "\n";
    }

    // 5. Final bottom border for the squares
    cout << "    ";
    for (int k = 0; k < 8; k++){
      if(k == 0){
        cout << "----+";
      }
      else{
        cout << "---+";
      }
    }
    cout << "\n";

    // 6. Column Labels at the BOTTOM
    cout << "    ";
    for (int j = 0; j < 8; j++) {
        cout << "  " << char(j + 97) << " ";
    }
    cout << "\n";
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

bool Board::isInside(int x, int y) { // Check if coordinates are within the 8x8 board
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    return true;
  else
    return false;
}

Piece *Board::getPiece(int x, int y) { return grid[x][y]; }
