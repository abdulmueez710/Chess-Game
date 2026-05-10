#include "Game.h"
#include "Board.h"
#include <iostream>
using namespace std;


Game::Game() : whiteTurn(true) {}

void Game::startGame() { board.initialize(); }

void Game::Menu(){
  cout << "1.  Start New Game\n";
  cout << "2.  Resume Previous Game\n";
  cout << "3.  Rules and Instructions\n";
  cout << "4.  Quit\n";
}

void Game::switchTurn() { 
  whiteTurn = !whiteTurn; 
}

void Game::takeInput() {
  cout << "\n";
  board.display(); // Display the board before taking input

  char col1, col2;  // column letters  (a-h)
  int row1, row2; // rank numbers (1-8, as shown on the board)

  cout << (whiteTurn ? "White" : "Black") << "'s turn (eg. e2 e4): ";
  cin >> col1;

  if (col1 == 'q' || col1 == 'Q') { // Quit the game on user will
    saveGame();
    cout << "\n\n               Game Saved & Ended\n";
    cout << "\n     Thank you for Playing Our Chess Game\n\n";

    exit(0);
  }

  cin >> row1 >> col2 >> row2;

  // Convert to lowercase in case the user types uppercase letters
  if (col1 >= 'A' && col1 <= 'H'){
    col1 = char(col1 + 32);
  }
  if (col2 >= 'A' && col2 <= 'H'){
    col2 = char(col2 + 32);
  }

  // Changing the index of Baord accordingly
  int Row1 = 8 - row1;
  int Row2 = 8 - row2;
  int Column1 = col1 - 'a';
  int Column2 = col2 - 'a';

  if (board.movePiece(Row1, Column1, Row2, Column2, whiteTurn)) {
    switchTurn(); // Switch turn only if the move was successful
    if (board.isInCheck(whiteTurn))
        if (board.isCheckmate(whiteTurn))
            cout << "Checkmate! " << (whiteTurn ? "Black" : "White") << " wins\n";
        else
            cout << (whiteTurn ? "White" : "Black") << " is in check!\n";
  } else {
    cout << "Invalid move. Try again." << endl;
  }
}

bool Game::checkGameEnd() {
    if (board.isCheckmate(false) || board.isCheckmate(true))
        return true;
    else
    return false;
}

void Game::saveGame() {
    board.saveToFile("chess_save.txt", whiteTurn);
}

bool Game::loadGame() {
    if (board.loadFromFile("chess_save.txt", whiteTurn)) {
        cout << "\nGame loaded successfully!\n";
        return true;
    }
    return false;
}
