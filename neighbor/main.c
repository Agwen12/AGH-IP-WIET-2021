#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int checkRow(int row, int col, int n, int A[n][n], int r);
int checkCol(int row, int col, int n, int A[n][n], int r);

int main() {
    int n, r;

    scanf("%d %d", &n, &r);
    int F[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &F[i][j]);
        }
    }

    int **W = (int **)malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++) { W[i] = (int *)calloc(n, n*sizeof(int)); }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            W[i][j] = checkCol(i, j, n, F, r);
        }
    }
    for (int i = 0; i < n; ++i) {
        printArray(W[i], n);
    }

    return 0;
}

int checkCol(int row, int col, int n, int A[n][n], int r) {
    int y = 0;
    int counter = 0;
    while (y <= r && col + y < n) {
        counter += checkRow(row, col + y, n, A, r);
        y += 1;
    }
    y = 1;
    while (y <= r && col - y >= 0) {
        counter += checkRow(row, col - y, n, A, r);
        y += 1;
    }
    return counter;
}

int checkRow(int row, int col, int n, int A[n][n], int r) {
    int x = 0;
    int counter = 0;
    while (x <= r && row + x < n) {
        if (A[row + x][col] == 1) { counter += 1; }
        x += 1;
    }
    x = 1;
    while (x <= r && row - x >= 0) {
        if (A[row - x][col] == 1) { counter += 1; }
        x += 1;
    }
    return counter;
}
