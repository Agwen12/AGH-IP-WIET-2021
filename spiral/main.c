#include <stdio.h>
#define N 100;

int main() {
    int n, k, a, b;
    scanf("%d", &n);
    int tab[n][n];

    k = 1;
    a = 0;
    b = n - 1;
    while (a <= b) {
        for (int i = a; i <= b; ++i) {
            tab[a][i] = k;
            k += 1;
        }

        for (int i = a + 1; i < b; ++i) {
            tab[i][b] = k;
            k += 1;
        }

        for (int i = b; a < i; --i) {
            tab[b][i] = k;
            k += 1;
        }

        for (int i = b; a < i; --i) {
            tab[i][a] = k;
            k += 1;
        }

        a += 1;
        b -= 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}
