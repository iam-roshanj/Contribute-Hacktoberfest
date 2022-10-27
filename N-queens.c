
#include <stdio.h>   
#include <conio.h> 
#include <stdbool.h>  
#include <Windows.h>   
#define N 8 

// This method is used to color the characters  
void Color(int col) {  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hConsole, col);  
}  

// This method print the final solution  
void printSolution(int board[N][N]) {  
    for (int i = 0; i < N; i++) {  
        for (int j = 0; j < N; j++) {  
            if (board[i][j] == 1) {  
                Color(2);  
                printf("%d ", board[i][j]);  
            } else {  
                Color(15);  
                printf("%d ", board[i][j]);  
            }  
        }  
        printf("\n");  
    }  
}  

// This method checks whether it is safe to place the queen in particular row and column.  
// This will return true if it is safe to place the queen and false otherwise.  
bool isSafe(int board[N][N], int row, int col) {  
    int i, j;  
    // Check this row on left side  
    for (i = 0; i < col; i++)  
        if (board[row][i]) return false;  
    // Check upper diagonal on left side   
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)  
        if (board[i][j]) return false;  
    // Check lower diagonal on left side   
    for (i = row, j = col; j >= 0 && i < N; i++, j--)  
        if (board[i][j]) return false;  
    return true;  
}  

// A recursive utility problem to solve N queens problem.  
bool solveNQUtil(int board[N][N], int col) {  
    // Base case: If all queens are placed then return true  
    if (col >= N) return true;  
    // Consider this column and try placing this queen in all rows one by one 
    for (int i = 0; i < N; i++) {  
        // Check if queen can be placed on board[i][col]  
        if (isSafe(board, i, col)) {  
            // Place this queen in board[i][col]   
            board[i][col] = 1;  
            // recur to place rest of the queens   
            if (solveNQUtil(board, col + 1)) return true;  
            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]  
            board[i][col] = 0; // BACKTRACK  
        }  
    }  
    // If queen can not be place in any row in this colum col then return false 
    return false;  
}  

// This function solves the N Queen problem using Backtracking. It mainly uses solveNQUtil() to solve the problem. 
// It returns false if queens cannot be placed, otherwise return true and prints placement of queens in the form of 1s. 
// Please note that there may be more than one solutions, this function prints one of the feasible soutions  
bool solveNQ() {  
    int board[N][N] = {{ 0, 0, 0, 0}, { 0, 0, 0, 0}, { 0, 0, 0, 0}, { 0, 0, 0, 0}};  
    if (solveNQUtil(board, 0) == false) {  
        printf("Solution does not exist");  
        return false;  
    }  
    printSolution(board);  
    return true;  
}  

int main() {  
    solveNQ();  
    _getch();  
    return 0;  
}  
