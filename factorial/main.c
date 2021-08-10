#include <stdio.h>

int main() {

    int n, value;
    int result[200];
    result[0] = 1;
    scanf("%d", &n);
    int inx = 1;
    int k = 1;
    int rest = 0;
    while (k <= n) {
        for (int i = 0; i < inx; ++i) {
            value = k * result[i] + rest;
            rest = value / 10;
            result[i] = value % 10;
        }

        while (rest != 0) {
            result[inx] = rest % 10;
            rest /= 10;
            inx += 1;
        }
        rest = 0;
        k += 1;
    }

    for (int j = inx - 1; j >= 0; --j) {
        printf("%d", result[j]);
    }
    return 0;
}
