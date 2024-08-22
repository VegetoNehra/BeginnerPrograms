#include <iostream>
#include <vector>
using namespace std;

#define N 8

void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    
    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    
    // Check the upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row) {
    // Base case: If all queens are placed
    if (row >= N) return true;
    
    // Consider this row and try placing a queen in all columns one by one
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place this queen in board[row][col]
            board[row][col] = 1;
            
            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, row + 1)) return true;
            
            // If placing queen doesn't lead to a solution, then backtrack
            board[row][col] = 0;
        }
    }
    
    // If the queen cannot be placed in any column in this row, return false
    return false;
}

bool solveNQueens() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }
    
    printSolution(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}
