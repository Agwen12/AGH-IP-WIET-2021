#include <stdio.h>
#include <stdlib.h>


int check_square(int **tab, int **output, int top, int size, int n, int expected);

int main() {
    int n, k, top;
    scanf("%d %d", &n, &k);

    int **A = (int **) malloc(100 * sizeof(int *));
    for (int i = 0; i < 100; i++) { A[i] = (int *) calloc(100, 100 * sizeof(int)); }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    int **output = (int **) malloc(9604 * sizeof(int *));
    for (int i = 0; i < 9604; i++) { output[i] = (int *) calloc(2, 2 * sizeof(int)); }
    top = 0;
    for (int i = 1; 2 * i + 1 < n + 1; ++i) {
        top = check_square(A, output, top, 2 * i + 1, n, k);
    }
    printf("%d\n", top);
    for (int i = 0; i < top; ++i) {
        printf("%d %d\n", output[i][0], output[i][1]);
    }
    return 0;
}

int check_square(int **tab, int **output, int top, int size, int n, int expected) {
    int sum;
    int _size = size / 2;
    for (int i = _size; i < n - _size; ++i) {
        for (int j = _size; j < n - _size; ++j) {
            sum = 0;
            for (int l = 0; l < size; ++l) {
                sum += tab[i - _size][j - _size + l];
                sum += tab[i + _size][j - _size + l];
            }
            for (int l = 0; l < size - 2; ++l) {
                sum += tab[i - _size + l + 1][j - _size];
                sum += tab[i - _size + l + 1][j + _size];
            }

            if (sum == expected) {
                output[top][0] = i;
                output[top][1] = j;
                top += 1;
            }
        }
    }
    return top;
}
