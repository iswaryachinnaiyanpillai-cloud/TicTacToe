#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// Score
int xWins = 0;
int oWins = 0;
int draws = 0;

// Display board
void displayBoard(const char board[]) {
    cout << "\n";
    cout << "========================================\n";
    cout << "              TIC TAC TOE\n";
    cout << "========================================\n\n";

    cout << "        " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "\n";
    cout << "    --------+-------+--------\n";
    cout << "        " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "\n";
    cout << "    --------+-------+--------\n";
    cout << "        " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "\n";

    cout << "\n";
}

// Check win
bool checkWin(const char board[], char player) {
    const int combinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[combinations[i][0]] == player &&
            board[combinations[i][1]] == player &&
            board[combinations[i][2]] == player) {
            return true;
        }
    }

    return false;
}

// Check draw
bool checkDraw(const char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] >= '1' && board[i] <= '9') {
            return false;
        }
    }

    return true;
}

// Get valid position
int getPosition(const char board[], char player) {
    int position;

    while (true) {
        cout << "Player " << player << ", enter position (1-9): ";

        cin >> position;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input! Enter a number from 1 to 9.\n\n";
            continue;
        }

        if (position < 1 || position > 9) {
            cout << "\nInvalid position! Choose a number from 1 to 9.\n\n";
            continue;
        }

        if (board[position - 1] == 'X' ||
            board[position - 1] == 'O') {
            cout << "\nThat position is already occupied!\n\n";
            continue;
        }

        return position;
    }
}

// Play one game
void playGame() {
    char board[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);

        int position = getPosition(board, currentPlayer);

        board[position - 1] = currentPlayer;

        // Check winner
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);

            cout << "========================================\n";
            cout << "           PLAYER " << currentPlayer << " WINS!\n";
            cout << "========================================\n";

            if (currentPlayer == 'X') {
                xWins++;
            } else {
                oWins++;
            }

            return;
        }

        // Check draw
        if (checkDraw(board)) {
            displayBoard(board);

            cout << "========================================\n";
            cout << "                 DRAW!\n";
            cout << "========================================\n";

            draws++;

            return;
        }

        // Switch player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
}

// Ask for replay
bool askReplay() {
    char choice;

    while (true) {
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;

        choice = static_cast<char>(
            toupper(static_cast<unsigned char>(choice))
        );

        if (choice == 'Y') {
            return true;
        }

        if (choice == 'N') {
            return false;
        }

        cout << "Invalid choice! Please enter Y or N.\n";
    }
}

// Show scoreboard
void showScoreboard() {
    cout << "\n";
    cout << "========================================\n";
    cout << "              SCORE BOARD\n";
    cout << "========================================\n";

    cout << "Player X Wins : " << xWins << "\n";
    cout << "Player O Wins : " << oWins << "\n";
    cout << "Draws         : " << draws << "\n";

    cout << "========================================\n";
}

// Show instructions
void showInstructions() {
    cout << "\n";
    cout << "========================================\n";
    cout << "              HOW TO PLAY\n";
    cout << "========================================\n\n";

    cout << "Player X goes first.\n";
    cout << "Player O goes second.\n\n";

    cout << "Choose a number from 1 to 9:\n\n";

    cout << "          1   |   2   |   3\n";
    cout << "        ------+-------+------\n";
    cout << "          4   |   5   |   6\n";
    cout << "        ------+-------+------\n";
    cout << "          7   |   8   |   9\n\n";

    cout << "Get three of your symbols in a row,\n";
    cout << "column, or diagonal to win.\n";

    cout << "\n========================================\n";
}

// Main menu
void showMenu() {
    int choice;

    while (true) {
        cout << "\n";
        cout << "========================================\n";
        cout << "          TIC TAC TOE GAME\n";
        cout << "========================================\n\n";

        cout << "1. Start Game\n";
        cout << "2. How to Play\n";
        cout << "3. Score Board\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input! Enter 1, 2, 3, or 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                do {
                    playGame();
                } while (askReplay());
                break;

            case 2:
                showInstructions();
                break;

            case 3:
                showScoreboard();
                break;

            case 4:
                cout << "\n========================================\n";
                cout << "       Thank you for playing!\n";
                cout << "              Goodbye!\n";
                cout << "========================================\n\n";
                return;

            default:
                cout << "\nInvalid choice! Please select 1-4.\n";
        }
    }
}

// Main
int main() {
    cout << "\n";
    cout << "========================================\n";
    cout << "       WELCOME TO TIC TAC TOE\n";
    cout << "========================================\n";

    cout << "\nPlayer 1: X\n";
    cout << "Player 2: O\n";

    showMenu();

    return 0;
}