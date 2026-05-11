#include "Piece.h"
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include <iostream>
#include <fstream>


using namespace std;

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = nullptr;
    }
  }
  enPassantRow = -1;
  enPassantCol = -1;
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
      for (int i = 0; i < 8; i++) {
            if (i == 4) {
                grid[7][i] = new King(true);
                grid[0][i] = new King(false);
            }
        }

        //   Queen display on board
      for (int i = 0; i < 8; i++) {
            if (i == 3) {
                grid[0][i] = new Queen(false);
                grid[7][i] = new Queen(true);
            }
        }

    // ---Knight ---
    for (int j = 0; j < 8; j++) {
        if (j == 1 || j == 6) {
            grid[0][j] = new Knight(false);
            grid[7][j] = new Knight(true);
        }
    }

    // ---Rook ---
    for (int j = 0; j < 8; j++) {
        if (j == 0 || j == 7) {
            grid[0][j] = new Rook(false);
            grid[7][j] = new Rook(true);
        }
    }
}
void Board::display() {
    // 1. Column Labels 
    cout << "    "; // Offset for row numbers
    for (int j = 0; j < 8; j++) {
          cout << "  " << char(j + 97) << " ";
    } 
    cout << "\n";

    for (int i = 0; i < 8; i++) {
        // 2. Top border for the squares ONLY
        cout << "    "; // Offset
        for (int k = 0; k < 8; k++){
          if(k == 0){
            cout << "+---+";
          }
          else
            cout << "---+";
        }
        cout << "\n";

        // 3. Row number on the left 
        cout << " " << (8 - i) << "  |"; 

        // 4. The actual pieces/squares
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr)
                cout << " . |";
            else
                cout << " " << grid[i][j]->getSymbol() << " |";
        }
        cout << " " << (8 - i); // Row number on the right side too
        cout << "\n";
    }

    // 5. Final bottom border for the squares
    cout << "    ";
    for (int k = 0; k < 8; k++){
      if(k == 0){
        cout << "+---+";
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
    Piece* movingPiece = grid[x1][y1];
    Piece* capturedPiece = grid[x2][y2];

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

    // En passant: the target square is empty, so remove the captured pawn beside the moving pawn
    if (target == nullptr && x2 == enPassantRow && y2 == enPassantCol) {
        int capturedPawnRow = x1; // The captured pawn sits on the same row as the moving pawn
        delete grid[capturedPawnRow][y2];
        grid[capturedPawnRow][y2] = nullptr;
    }

    grid[x2][y2] = movingPiece;
    grid[x1][y1] = nullptr;

    // Check if own king is in check
    if (isInCheck(whiteTurn)) {
        grid[x1][y1] = movingPiece;
        grid[x2][y2] = capturedPiece;
        return false;
    }

    // Legal move � now delete captured piece
    if (capturedPiece != nullptr) {
        delete capturedPiece;
    }

    p->setHasMoved(true);

    // Update en passant target: set if pawn just double-stepped, clear otherwise
    if (p->getSymbol() == 'P' || p->getSymbol() == 'p') {
        if (abs(x2 - x1) == 2) {
            enPassantRow = (x1 + x2) / 2; // The skipped square
            enPassantCol = y1;
        } 
        else {
            enPassantRow = -1;
            enPassantCol = -1;
        }
    } 
    else {
        enPassantRow = -1;
        enPassantCol = -1;
    }

    // --- Pawn Promotion ---
    // White pawn reaches row 0, black pawn reaches row 7
    bool isWhitePawn = (p->getSymbol() == 'P');
    bool isBlackPawn = (p->getSymbol() == 'p');
    if ((isWhitePawn && x2 == 0) || (isBlackPawn && x2 == 7)) {
        char choice = '\0';
        while (true) {
            cout << "Pawn promotion! Choose a piece:\n";
            cout << "  Q = Queen  |  R = Rook  |  B = Bishop  |  N = Knight\n";
            cout << "Your choice: ";
            cin >> choice;
            if (choice >= 'a' && choice <= 'z') choice -= 32; // manual to-uppercase
            if (choice == 'Q' || choice == 'R' || choice == 'B' || choice == 'N')
            break;
            cout << "Invalid choice. Please enter Q, R, B, or N.\n";
        }

        bool pawnColor = p->getColor(); // true = white, false = black
        delete grid[x2][y2];            // Remove the pawn from the board
        grid[x2][y2] = nullptr;

        switch (choice) {
            case 'Q': grid[x2][y2] = new Queen(pawnColor);  break;
            case 'R': grid[x2][y2] = new Rook(pawnColor);   break;
            case 'B': grid[x2][y2] = new Bishop(pawnColor); break;
            case 'N': grid[x2][y2] = new Knight(pawnColor); break;
        }
    }

    return true;
}

bool Board::isInside(int x, int y) { // Check if coordinates are within the 8x8 board
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
    else
        return false;
}

bool Board::isInCheck(bool white) {
    int kingRow = -1; int kingCol = -1;
    char kingSymbol = white ? 'K' : 'k';
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() == kingSymbol) {
                kingRow = i; kingCol = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getColor() != white && grid[i][j]->isValidMove(i, j, kingRow, kingCol, this) == true) {
                return true;
            }
        }
    }
    return false;

}

bool Board::isCheckmate(bool white) {
    if (!isInCheck(white))
        return false;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr || grid[i][j]->getColor() != white)
                continue;

            Piece* p = grid[i][j];

            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    Piece* target = grid[k][l];
                    if (target != nullptr && target->getColor() == white)
                        continue; // friendly fire, skip
                    if (!p->isValidMove(i, j, k, l, this))
                        continue; // invalid move, skip

                    // Simulate
                    grid[k][l] = p;
                    grid[i][j] = nullptr;

                    bool stillInCheck = isInCheck(white);

                    // Undo
                    grid[i][j] = p;
                    grid[k][l] = target;

                    if (!stillInCheck)
                        return false; // found a legal move, not checkmate
                }
            }
        }
    }
    return true; // no legal move found
}

Piece *Board::getPiece(int x, int y) { return grid[x][y]; }

bool Board::saveToFile(const string& filename, bool whiteTurn) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not save the game." << endl;
        return false;
    }

    // First line: whose turn it is (1 = white, 0 = black)
    file << (whiteTurn ? 1 : 0) << endl;

    // Save the 8x8 grid
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr) {
                file << ".";
            } else {
                file << grid[i][j]->getSymbol();
            }
        }
        file << endl;
    }

    file.close();
    return true;
}

bool Board::loadFromFile(const string& filename, bool& whiteTurn) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: No saved game found." << endl;
        return false;
    }

    // Read whose turn it is
    int turn;
    file >> turn;
    whiteTurn = (turn == 1);

    // Clear the current board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }

    // Read the 8x8 grid
    string row;
    for (int i = 0; i < 8; i++) {
        file >> row;
        for (int j = 0; j < 8; j++) {
            char ch = row[j];

            switch (ch) {
                case 'P': grid[i][j] = new Pawn(true);    break;
                case 'p': grid[i][j] = new Pawn(false);   break;
                case 'R': grid[i][j] = new Rook(true);    break;
                case 'r': grid[i][j] = new Rook(false);   break;
                case 'N': grid[i][j] = new Knight(true);   break;
                case 'n': grid[i][j] = new Knight(false);  break;
                case 'B': grid[i][j] = new Bishop(true);   break;
                case 'b': grid[i][j] = new Bishop(false);  break;
                case 'Q': grid[i][j] = new Queen(true);    break;
                case 'q': grid[i][j] = new Queen(false);   break;
                case 'K': grid[i][j] = new King(true);     break;
                case 'k': grid[i][j] = new King(false);    break;
                default:  grid[i][j] = nullptr;             break;
            }
        }
    }

    file.close();
    enPassantRow = -1;
    enPassantCol = -1;
    return true;
}