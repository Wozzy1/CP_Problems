#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

void readFile(const char* filename, int grid[GRID_SIZE][GRID_SIZE]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (fscanf(file, "%d", &grid[i][j]) != 1) {
                fprintf(stderr, "Error reading data from file\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

int mult_nw(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row - 3 < 0 || col - 3 < 0) {
        return -1;
    }
    int prod = 1;
    for (int i = 0; i < 4; i++) {
        prod *= grid[row+i][col+i];
        if (!prod) return 0;
    }
    return prod;
}

int mult_ne(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row - 3 < 0 || col + 3 > GRID_SIZE) {
        return -1;
    }
    int prod = 1;
    for (int i = 0; i < 4; i++) {
        prod *= grid[row-i][col+i];
        // printf("%d %d %d \n", grid[row-i][col+i], row-i, col+i);
        if (!prod) return 0;
    }
    return prod;
}

int mult_se(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row + 3 > GRID_SIZE || col + 3 > GRID_SIZE) {
        return -1;
    }
    int prod = 1;
    for (int i = 0; i < 4; i++) {
        prod *= grid[row+i][col+i];
        // printf("%d %d %d \n", grid[row+i][col+i], row+i, col+i);
        if (!prod) return 0;
    }
    return prod;
}

int mult_sw(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row + 3 > GRID_SIZE || col - 3 < 0) {
        return -1;
    }
    int prod = 1;
    for (int i = 0; i < 4; i++) {
        prod *= grid[row+i][col-i];
        // printf("%d %d %d \n", grid[row+i][col-i], row+i, col-i);
        if (!prod) return 0;
    }
    return prod;
}

int mult_right(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Check if valid, then return product
    if (col + 4 > GRID_SIZE) {  // Prevent out-of-bounds access
        return -1;
    }
    int prod = 1;
    for (int i = col; i < col + 4; i++) {
        prod *= grid[row][i];
        if (!prod) return 0;
    }
    return prod;
}

int mult_left(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Check if valid, then return product
    if (col - 3 < 0) {  // Prevent out-of-bounds access
        return -1;
    }
    int prod = 1;
    for (int i = col - 3; i <= col; i++) {  // Adjusted range
        prod *= grid[row][i];
        if (!prod) return 0;
    }
    return prod;
}

int mult_up(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Check if valid, then return product
    if (row - 3 < 0) {  // Prevent out-of-bounds access
        return -1;
    }
    int prod = 1;
    for (int i = row - 3; i <= row; i++) {  // Adjusted range
        prod *= grid[i][col];
        if (!prod) return 0;
    }
    return prod;
}

int mult_down(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Check if valid, then return product
    if (row + 4 > GRID_SIZE) {  // Prevent out-of-bounds access
        return -1;
    }
    int prod = 1;
    for (int i = row; i < row + 4; i++) {
        prod *= grid[i][col];
        if (!prod) return 0;
    }
    return prod;
}

int max_(int num1, int num2) {
    return (num1 < num2 ? num2 : num1);
}

int main() {
    // 1-indexed grid
    //          row        col
    int grid[GRID_SIZE][GRID_SIZE];
    readFile("grid.txt", grid);

    int largest = -1;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) { 
            largest = max_(largest, mult_up(grid, i, j));
            largest = max_(largest, mult_down(grid, i, j));
            largest = max_(largest, mult_right(grid, i, j));
            largest = max_(largest, mult_left(grid, i, j));

            largest = max_(largest, mult_nw(grid, i, j));
            largest = max_(largest, mult_ne(grid, i, j));
            largest = max_(largest, mult_se(grid, i, j));
            largest = max_(largest, mult_se(grid, i, j));
        }
    }
    
    printf("\nLargest: %d\n", largest);

    return 0;
}
