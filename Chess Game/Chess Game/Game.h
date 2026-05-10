#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <string>
using namespace std;

class Game {
private:
	Board board;  // Composition: Game has a Board
    bool whiteTurn;

public:
    Game();
    void Menu();
    void startGame();
    void switchTurn();
    void takeInput();
    bool checkGameEnd();
    void saveGame();
    bool loadGame();
};

#endif 