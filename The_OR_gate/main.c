#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    unsigned int result, G, x, y, idx;
    scanf("%u %u", &n, &G);
    unsigned int *bitTab = calloc(32, sizeof(int));
    unsigned int *T = malloc((unsigned )n* sizeof(int));

    // scan numbers for T
    for (int i = 0; i < n; ++i) {
        scanf("%u", &T[i]);
    }

    // remove all incompatible numbers
    for (int i = 0; i < n; ++i) {
        if ((T[i] | G) != G) T[i] = 0;
    }

    // filling bitTab with "bit sums" of all numbers in T
    for (int i = 0; i < n; ++i) {
        x = T[i];
        y = 0;
        while (x > 0) {
            bitTab[y] += x % 2;
            x /= 2;
            y++;
        }
    }


    // getting minimal number of element form T to remove
    idx = 0;
    result = 99999;
    while (G > 0) {
        if (bitTab[idx] < result && G % 2 == 1) result = bitTab[idx];
        G /= 2;
        idx++;
    }

    // free memory, print result and stuff..
    free(T);
    free(bitTab);
    printf("%u", result);
    return 0;

}
