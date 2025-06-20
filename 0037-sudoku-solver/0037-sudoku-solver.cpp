#include <vector>
using namespace std;

class Solution {
public:
    // Checkinbg each number if it is safe for that place or not
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        int N = board.size(); // Size of the board (assume N x N)

        // Check the row and column for that particular position
        for (int x = 0; x < N; x++) {
            if (board[row][x] == num || board[x][col] == num) {
                return false;
            }
        }

        // Check the 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Recursive backtracking function to solve the Sudoku
    bool solve(vector<vector<char>>& board) {
        int N = board.size(); // Size of the board (assume N x N)

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (board[row][col] == '.') { // Empty cell found
                    for (char num = '1'; num <= '9'; num++) { // Try numbers '1'-'9'
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num; // Place the number
                            if (solve(board)) { // Recursively solve for the next cell
                                return true;
                            }
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // Trigger backtracking
                }
            }
        }
        return true; // Puzzle solved
    }

    // Wrapper function for solving Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Solve the Sudoku board in place
    }
};
