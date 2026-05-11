#include "Game.h"
#include "Board.h"
#include <iostream>
using namespace std;


Game::Game() : whiteTurn(true) {}

void Game::startGame() { board.initialize(); }

void Game::Menu(){
  cout << "\n1.  Start New Game\n";
  cout << "2.  Resume Previous Game\n";
  cout << "3.  Rules and Instructions\n";
  cout << "4.  Quit\n";
}

void Game::instructions(){
  cout << "==================== CHESS GAME INSTRUCTIONS ====================\n\n";

cout << "1. This is a two-player chess game:\n";
cout << "   - White moves first\n";
cout << "   - Players take turns one by one\n\n";

cout << "2. Enter moves in the following format:\n";
cout << "      e2 e4\n\n";

cout << "   Example:\n";
cout << "      e2 e4  -> moves piece from e2 to e4\n\n";

cout << "3. Board Coordinates:\n";
cout << "   - Columns are labeled from a to h\n";
cout << "   - Rows are labeled from 1 to 8\n\n";

cout << "4. Piece Symbols:\n\n";

cout << "   White Pieces:\n";
cout << "      K = King\n";
cout << "      Q = Queen\n";
cout << "      R = Rook\n";
cout << "      B = Bishop\n";
cout << "      N = Knight\n";
cout << "      P = Pawn\n\n";

cout << "   Black Pieces:\n";
cout << "      k = King\n";
cout << "      q = Queen\n";
cout << "      r = Rook\n";
cout << "      b = Bishop\n";
cout << "      n = Knight\n";
cout << "      p = Pawn\n\n";

cout << "5. Special Rules Included:\n";
cout << "   - Pawn Promotion\n";
cout << "   - En Passant\n";
cout << "   - Check Detection\n";
cout << "   - Checkmate Detection\n";
cout << "   - Stalemate Detection\n\n";

cout << "6. Invalid moves are not allowed.\n";
cout << "   You cannot:\n";
cout << "   - Move outside the board\n";
cout << "   - Move opponent's piece\n";
cout << "   - Capture your own piece\n";
cout << "   - Leave your king in check\n\n";

cout << "7. To quit the game at any time, type:\n";
cout << "      quit\n\n";

cout << "8. Game End Conditions:\n";
cout << "   - Checkmate  -> One player wins\n";
cout << "   - Stalemate  -> Match draw\n\n";

cout << "=================================================================\n";
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
    if (board.isInCheck(whiteTurn)){
        if (board.isCheckmate(whiteTurn)){
            cout << "Checkmate! " << (whiteTurn ? "Black" : "White") << " wins\n";
        }
        else{
            cout << (whiteTurn ? "White" : "Black") << " is in check!\n";
        }
    }
  } 
  else {
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
