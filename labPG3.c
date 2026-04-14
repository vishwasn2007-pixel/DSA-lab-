// Program to implement Sudoku structure and search in row, column and grid
#include <stdio.h>

int isInRow(int grid[9][9], int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num)
            return 1;
    }
    return 0;
}

int isInCol(int grid[9][9], int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(grid[row][col] == num)
            return 1;
    }
    return 0;
}

int isInBox(int grid[9][9], int startRow, int startCol, int num) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[startRow + i][startCol + j] == num)
                return 1;
        }
    }
    return 0;
}

int main() {
    int grid[9][9];
    int num, row, col;

    printf("Enter 9x9 Sudoku grid:\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter number to search: ");
    scanf("%d", &num);

    printf("Enter row and column (0-8): ");
    scanf("%d %d", &row, &col);

    if(isInRow(grid, row, num))
        printf("Number found in row\n");
    else
        printf("Number not found in row\n");

    if(isInCol(grid, col, num))
        printf("Number found in column\n");
    else
        printf("Number not found in column\n");

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    if(isInBox(grid, startRow, startCol, num))
        printf("Number found in grid\n");
    else
        printf("Number not found in grid\n");

    return 0;
}