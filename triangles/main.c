#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **A = (int **)malloc((unsigned)(n + 1)*sizeof(int *));
    for (int i = 0; i < n + 1; i++)
        A[i] = (int *)calloc((unsigned)(n + 1), (unsigned)(n + 1)*sizeof(int));

    int row, col;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &row, &col);
        A[row][col] = 1;
    }


    int counter = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = i + 1; j < n + 1; ++j) {
            for (int k = j + 1; k < n + 1; ++k) {
                if ((A[i][j] == A[i][k]) && (A[i][j] == A[j][k])) { counter++; }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        free(A[i]);
    }
    free(A);
    printf("%d", counter);
    return 0;
}
