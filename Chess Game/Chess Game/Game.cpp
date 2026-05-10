#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : whiteTurn(true) {}

void Game::startGame() { board.initialize(); }

void Game::switchTurn() { 
  whiteTurn = !whiteTurn; 
}

void Game::takeInput() {
  cout << "\n";
  board.display(); // Display the board before taking input

  char col1, col2;  // column letters  (a-h)
  int row1, row2; // rank numbers (1-8, as shown on the board)

  cout << (whiteTurn ? "White" : "Black") << "'s turn (e.g e2 e4): ";
  cin >> col1 >> row1 >> col2 >> row2;

  // Convert to lowercase in case the user types uppercase letters
  if (col1 >= 'A' && col1 <= 'Z'){
    col1 += 32;
  }
  if (col2 >= 'A' && col2 <= 'Z'){
    col2 += 32;
  }

  // Changing the index of Baord accordingly
  int Row1 = 8 - row1;
  int Row2 = 8 - row2;
  int Column1 = col1 - 'a';
  int Column2 = col2 - 'a';

  if (board.movePiece(row1, Column1, row2, Column2, whiteTurn)) {
    switchTurn(); // Switch turn only if the move was successful
  } else {
    cout << "Invalid move. Try again." << endl;
  }
}

bool Game::checkGameEnd() {
  // Placeholder for game end logic (e.g., checkmate, stalemate)
  return false;
}
