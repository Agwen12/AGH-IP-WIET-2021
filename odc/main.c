#include <stdio.h>
#include <stdlib.h>

int** callocArray2D(int r, int c);

void get_sums(int**, int row, int col, int n, int* ans);

int ends(int a, int n);



int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    //    char temp;
//    for (int i = 0; i < n; ++i) {
//        int j = 0;
//        do {
//            scanf("%d%c", &T[i][j], &temp);
//            j++;
//        } while (temp != '\n' && j < n);
//    }



//    int** T = callocArray2D(n, n);
    int **T = (int **)malloc((unsigned int)n*sizeof(int *));
    for (int i = 0; i < n; i++)
        T[i] = (int *)calloc((unsigned int)n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &T[i][j]);
        }
    }

    int ans[3];
    int max_sum = -2147483646;
    int temp_sum;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp_sum = T[i][j];
            ans[1] = i;
            ans[2] = j;
//            printf("<<< %d %d\n", i, j);
            for (int l = 0; l < k - 1; ++l) {
                get_sums(T, ans[1], ans[2], n, ans);
                temp_sum += ans[0];
            }
            if (temp_sum > max_sum) { max_sum = temp_sum; }
//            printf("%d\n\n", temp_sum);
        }
    }

    printf("%d", max_sum);

    return 0;
}


void get_sums(int** T, int row, int col, int n, int* ans) {
    int max, max_r, max_c;
    max = -2147483646;
    for (int i = row - 1; i < row + 2 ; ++i) {
        for (int j = col - 1; j <col + 2 ; ++j) {
            if ( i != row && j != col && (T[ends(i, n)][ends(j, n)] >= max)) {
                max = T[ends(i, n)][ends(j, n)];
                max_r = ends(i, n);
                max_c = ends(j, n);
            }
        }
    }

    ans[0] = max;
    ans[1] = max_r;
    ans[2] = max_c;
//    printf("%d %d %d\n", max, max_r, max_c);
}

int ends(int a, int n) {
    if (a >= n) {
        return 0;
    } else if (a < 0) {
        return n - 1;
    } else {
        return a;
    }
}
