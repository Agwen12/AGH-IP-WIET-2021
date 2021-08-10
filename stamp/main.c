#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);

    int **T = (int **)malloc((unsigned int)n*sizeof(int *));
    for (int i = 0; i < n; i++)
        T[i] = (int *)calloc((unsigned int)n, sizeof(int));

    int **P = (int **)malloc((unsigned int)k*sizeof(int *));
    for (int i = 0; i < k; i++)
        P[i] = (int *)calloc((unsigned int)l, sizeof(int));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &T[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            scanf("%d", &P[i][j]);
        }
    }

    int max_sum = -2147483646;
    for (int i = 0; i < n - k; ++i) {
        for (int j = 0; j < n - l; ++j) {
            int tem_sum = 0;
            for (int row = 0; row < k; ++row) {
                for (int col = 0; col < l; ++col) {
                    if (P[row][col]) { tem_sum += T[i + row][j + col]; }
                }
            }
            if (tem_sum > max_sum) { max_sum = tem_sum; }

        }
    }

    printf("%d", max_sum);
    return 0;
}
