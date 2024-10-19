#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 4  

void populateMatrix(int matrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            matrix[row][col] = rand() % 100;
        }
    }
}

void displayMatrix(int matrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }
}

void swapDiagonal(int matrix[SIZE][SIZE]) {
    int x, y;
    for (x = 0; x < SIZE; x++) {
        for (y = x + 1; y < SIZE; y++) {
            int holder = matrix[x][y];
            matrix[x][y] = matrix[y][x];
            matrix[y][x] = holder;
        }
    }
}

int main() {
    int matrix[SIZE][SIZE];
    srand(time(NULL));  
    populateMatrix(matrix);

    printf("Initial Matrix:\n");
    displayMatrix(matrix);

    swapDiagonal(matrix);

    printf("\nMatrix After Transposition:\n");
    displayMatrix(matrix);

    return 0;
}
