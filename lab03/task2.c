#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 41 - 20;
        }
    }

    printf("Pochatkova matrytsia (%dx%d):\n", ROWS, COLS);
    print_matrix(matrix);
    printf("\n");

    int max_sum = 0;
    int max_row = 0;

    for (int i = 0; i < ROWS; i++) {
        int current_sum = 0;
        for (int j = 0; j < COLS; j++) {
            current_sum += matrix[i][j];
        }

        if (i == 0 || current_sum > max_sum) {
            max_sum = current_sum;
            max_row = i;
        }
    }

    printf("Riadok iz maksymalnoiu sumoiu: indeks %d (riadok №%d), suma = %d\n\n",
           max_row, max_row + 1, max_sum);

    for (int j = 0; j < COLS; j++) {
        matrix[max_row][j] = -matrix[max_row][j];
    }

    printf("Matrytsia pislia invertuvannia znakiv u riadku №%d:\n", max_row + 1);
    print_matrix(matrix);

    return 0;
}