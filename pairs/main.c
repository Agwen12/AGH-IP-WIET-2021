#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], unsigned int N)
{
    for (unsigned int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int cmpFunc (const void *a, const void *b) { return *(int*)a - *(int*)b; }


int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);

    unsigned int N = (unsigned int) n;
    int* tab = (int*)calloc(N, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &tab[i]);

    qsort(tab, N, sizeof(int), cmpFunc);
//    printArray(tab, n);



    int i = 0;
    int pair_counter = 0;
    int idx = 0;
    while (i < n) {
        idx = i;
        while (idx + 1 < n && tab[idx + 1] == tab[idx]) { idx += 1; }

        if (idx + 1 < n && tab[idx + 1] - tab[idx] <= k) {
            pair_counter = pair_counter + idx - i + 1;
        } else if (i - 1 >= 0 && tab[i] - tab[i - 1] <= k) {
            pair_counter = pair_counter + idx - i + 1;
        }
        i = idx + 1;
    }

    printf("%d", pair_counter);

    return 0;
}
