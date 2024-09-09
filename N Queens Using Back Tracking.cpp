#include <stdio.h>
#define N 8  // You can change this value for a different size of the chessboard

int board[N][N];

// Function to print the solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)  // Check left side of the row
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)  // Check upper diagonal on left side
        if (board[i][j])
            return 0;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)  // Check lower diagonal on left side
        if (board[i][j])
            return 0;

    return 1;
}

// Function to solve n-Queens problem using backtracking
int solveNQ(int col) {
    if (col >= N) {  // If all queens are placed
        printSolution();
        return 1;
    }

    for (int i = 0; i < N; i++) {  // Consider this column and try placing this queen in all rows one by one
        if (isSafe(i, col)) {  // Check if queen can be placed on board[i][col]
            board[i][col] = 1;  // Place the queen

            if (solveNQ(col + 1))  // Recursively place the rest of the queens
                return 1;

            board[i][col] = 0;  // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
        }
    }

    return 0;  // If queen cannot be placed in any row in this column col, return 0
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;  // Initialize the board with 0

    if (!solveNQ(0)) {
        printf("Solution does not exist\n");
    }

    return 0;
}
