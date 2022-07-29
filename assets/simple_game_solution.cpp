#include <iostream>
#include <cstdlib>

using namespace std;

class TicTacToeGame {
    private:
        char board[3][3];
        int filled_squares = 0;
        string player1_name;
        string player2_name;

    public:
        TicTacToeGame(string p1, string p2) {
            player1_name = p1;
            player2_name = p2;

            for(int i = 0; i < 3; i++) {
                for (int i = 0; i < 3; i++) {
                    board[i][i] = ' ';
                }
            }
        }

        string getPlayerName(int player_num) {
            string name;
            switch (player_num) {
                case 1:
                    name = player1_name;
                    break;
                case 2:
                    name = player2_name;
            }
            return name;
        }

        void clearBoard() {
            for (int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
        }

        void placeChar(char c, int row, int col) {
            if (checkEmptySquare(row, col)) {
                board[row][col] = c;
            }
        }

        void printBoard() {
            cout << "   0 | 1 | 2" << endl;
            cout << "   _________" << endl;
            for (int i = 0; i < 3; i++) {
                cout << i;
                for (int j = 0; j < 3; j++) {
                    cout << "| " << board[i][j] << " ";
                }
                cout << endl << "   _________" << endl;

            }
        }

        bool checkWin(char c) {
            // check for 3 in a row horizontally and vertically
            for (int i = 0; i < 2; i++) {
                if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                    return true;
                } else if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                }
                    return true;
            }

            // check for 3 in a row diagonally
            if (board[0][0] == c || board[1][1] == c || board[2][2] == c) {
                return true;
            } else if (board[0][2] == c || board[1][1] == c || board[2][0] == c) {
                return true;
            }
            return false;
        }
        bool checkFull() {
            return (filled_squares >= 8);
        }
        bool checkEmptySquare(int row, int col) {
            return (board[row][col] == ' ');
        }
        char checkSquareValue(int row, int col) {
            return board[row][col];
        }
};

void testTicTacToe() {
    TicTacToeGame game = TicTacToeGame("Ann", "Marie");  // DO NOT MODIFY THIS LINE ----------------------------

    // You can add code here if you wish (optional) vvvvvvvvvv



    // DO NOT MODIFY WITHIN THIS BLOCK --------------------

    // TEST 1: name getting and setting
    // 1 bug (switch statement)
    string p1 = game.getPlayerName(1);
    string p2 = game.getPlayerName(2);
    if(p1 != "Ann"|| p2 != "Marie") {
        cout << "TEST 1 ERROR: getPlayerName for both players, expected Ann & Marie, got " << p1 << " and " << p2 << endl;
    }

    // TEST 2: testing placeChar some more
    // 2ish bugs: placeChar var swap, initialization
    game.placeChar('x', 0, 1);
    if(game.checkSquareValue(0, 1) != 'x') {
        cout << "TEST 2 ERROR: placeChar didn't properly place a character." << endl;
        game.printBoard();
    }

    // TEST 3: testing checkEmptySquare
    // 1 bug (== vs =)
    game.placeChar('x', 1, 0);
    if(game.checkEmptySquare(1, 0)) {
        cout << "TEST 3 ERROR: checkEmptySquare returned true when it shouldn't have" << endl;
        game.printBoard();
    }

    // TEST 4: testing checkFull
    // 1 bug (missing variable update)
    game.placeChar('o', 0, 0);
    game.placeChar('x', 0, 1);
    game.placeChar('x', 0, 2);
    game.placeChar('x', 1, 1);
    game.placeChar('o', 1, 2);
    game.placeChar('x', 2, 0);
    game.placeChar('o', 2, 1);
    game.placeChar('o', 2, 2);

    if(!game.checkFull()) {
        cout << "TEST 4 ERROR: checkFull returned false when board should be full" << endl;
        game.printBoard();
    }

    // TESTS 5-6: testing checkWin
    // 1 bug: || instead of &&
    if(!game.checkWin('x') || game.checkWin('o')) {
        cout << "TEST 5 ERROR: checkWin returned an incorrect value (expected x wins, o loses)" << endl;
        game.printBoard();
    }

    //  1 bug: incorrect loop condition
    TicTacToeGame game2 = TicTacToeGame("me", "you");
    game2.placeChar('o', 2, 0);
    game2.placeChar('o', 2, 1);
    game2.placeChar('o', 2, 2);
    if(!game2.checkWin('o') || game2.checkWin('x')) {
        cout << "TEST 6 ERROR: checkWin returned an incorrect value (expected o wins, x loses)" << endl;
        game2.printBoard();
    }

    // END OF DO-NOT-MODIFY ----------------------
}

// DO NOT EDIT
int main() {
    testTicTacToe();
    return 0;
}