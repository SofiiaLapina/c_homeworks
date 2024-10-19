#include <stdio.h>

void fill_array(int N, char array[N][N]) {
    char symbols[6] = {'*', '=', '+', '*', '+', '='};
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int k = i + j;
            array[i][j] = symbols[k % 6];
        }
    }
}

void print_array(int N, char array[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the size of the matrix (N): ");
    if(scanf("%d", &N) != 1) {
        printf("Input error.\n");
        return 1;
    }

    if (N <= 0 || N > 1000) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    char array[N][N];

    fill_array(N, array);

    print_array(N, array);

    return 0;
}
