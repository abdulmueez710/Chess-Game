#include "Game.h"
#include <iostream>

using namespace std;

int main() {
  Game chessGame;

  chessGame.Menu();
  int choice;
  do {
    cout << "\nEnter your Choice : ";
    cin >> choice;
    if (choice == 1) {
      chessGame.startGame();
      // Main game loop with taking input and checking for game end
      while (!chessGame.checkGameEnd()) {
        chessGame.takeInput();
      }
    } else if (choice == 2) {
      if (chessGame.loadGame()) {
        // Resume: game loop with loaded state
        while (!chessGame.checkGameEnd()) {
          chessGame.takeInput();
        }
      } else {
        cout << "Could not resume. Starting a new game instead.\n";
        chessGame.startGame();
        while (!chessGame.checkGameEnd()) {
          chessGame.takeInput();
        }
      }
    } else if (choice == 3) {
      cout << "\n\nInstructions baad mai add karoon ga mai\n\n";
    } else if (choice == 4) {
      exit(0);
    } else {
      cout << "Invalid choice\n";
    }
  } while (choice != 4);
  return 0;
}
