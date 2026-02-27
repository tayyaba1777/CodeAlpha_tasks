#include <iostream>
using namespace std;

const int N = 9;

// Print Board
void printBoard(int board[N][N]) {
    cout << "\n===== SOLVED SUDOKU =====\n\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if safe
bool isSafe(int board[N][N], int row, int col, int num) {

    // Row check
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    // 3x3 Box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Solve Sudoku
bool solveSudoku(int board[N][N]) {

    int row, col;
    bool emptyFound = false;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound)
            break;
    }

    if (!emptyFound)
        return true;

    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {

    int board[N][N];

    cout << "=========================================\n";
    cout << "        9 x 9 SUDOKU SOLVER\n";
    cout << "=========================================\n\n";

    cout << "INSTRUCTIONS:\n";
    cout << "1. You must fill 9 rows and 9 columns.\n";
    cout << "2. Enter 9 numbers in each row.\n";
    cout << "3. Use 0 for empty cells.\n";
    cout << "4. Total numbers to enter = 81.\n\n";

    for (int i = 0; i < N; i++) {
        cout << "Enter 9 numbers for Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
        printBoard(board);
    else
        cout << "\nNo solution exists.";

    return 0;
}
