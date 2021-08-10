#include <stdio.h>
#include <stdlib.h>

void revers(int **tab, int row, int col);

int main() {
    int n;
    int **A = (int **) malloc(202 * sizeof(int *));
    for (int i = 0; i < 202; i++)
        A[i] = (int *) calloc(202, 202 * sizeof(int));
    scanf("%d", &n);


    int row1, row2, col1, col2;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
        for (int j = row1 + 100; j < row2 + 100; ++j) {
            for (int k = col1 + 100; k < col2 + 100; ++k) {
                revers(A, j, k);
            }
        }
    }

    for (int i = 0; i < 202; ++i) {
        for (int j = 0; j < 202; ++j) {
            if (A[i][j] == 1) { counter += 1; }
        }
    }

    printf("%d", counter);

    for (int i = 0; i < 202; ++i) {
        free(A[i]);
    }
    free(A);
    return 0;
}


void revers(int **tab, int row, int col) {
    if (tab[row][col] == 0) {
        tab[row][col] = 1;
    } else {
        tab[row][col] = 0;
    }
}