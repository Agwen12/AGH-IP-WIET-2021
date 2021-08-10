#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c, int d);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int **T = (int **)malloc((unsigned int)n*sizeof(int *));
    for (int i = 0; i < n; ++i)
        T[i] = (int *)calloc((unsigned int)n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &T[i][j]);
        }
    }


    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int right = 0, right_sum = 0;
            while (right < k) {
                right_sum += T[i][(j + right) % n];
                right++;
            }

            int left_diag = 0, left_diag_sum = 0;
            while (left_diag < k) {
                int _i = (i + left_diag) % n;
                int _j = (j - left_diag) % n;
                if (_j < 0) {
                    _j = n + _j;
                }
                left_diag_sum += T[_i][_j];
                left_diag++;
            }

            int down = 0, down_sum = 0;
            while (down < k) {
                down_sum += T[(i + down) % n][j];
                down++;
            }

            int right_diag = 0, right_diag_sum = 0;
            while (right_diag < k) {
                right_diag_sum += T[(i + right_diag) % n][(j + right_diag) % n];
                right_diag++;
            }

            int max_temp = max(right_sum, down_sum, right_diag_sum, left_diag_sum);
            if (max_temp > max_sum) {
                max_sum = max_temp;
            }
        }
    }

    printf("%d", max_sum);

    return 0;
}


int max(int a, int b, int c, int d) {
    int ret1, ret2;
    if (a >= b) {
        ret1 = a;
    } else {
        ret1 = b;
    }

    if (c >= d) {
        ret2 = c;
    } else {
        ret2 = d;
    }

    if (ret1 >= ret2) {
        return ret1;
    } else {
        return ret2;
    }
}