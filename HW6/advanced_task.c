#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fill_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            *(arr + i * size + j) = rand() % 11;
        }
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%2d ", *(arr + i * size + j));
        }
        printf("\n");
    }
}

void zero_out_rows_and_columns(int* arr, int size) {
    int zero_rows[SIZE] = {0};
    int zero_cols[SIZE] = {0};

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (*(arr + i * size + j) == 0) {
                zero_rows[i] = 1;
                zero_cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (zero_rows[i] == 1 || zero_cols[j] == 1) {
                *(arr + i * size + j) = 0;
            }
        }
    }
}

int main() {
    int matrix[SIZE][SIZE];

    srand(time(NULL));
    fill_array((int*)matrix, SIZE);

    printf("Original matrix:\n");
    print_array((int*)matrix, SIZE);

    zero_out_rows_and_columns((int*)matrix, SIZE);

    printf("\nModified matrix:\n");
    print_array((int*)matrix, SIZE);

    return 0;
}
