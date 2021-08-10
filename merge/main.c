#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int t1[N][N];
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &t1[j][i]);
        }
    }

    int* indexTab = (int*)calloc(N, sizeof(int));
    int* A = (int*)calloc(N*N, sizeof(int));
    int ind = 0;
    int sum = 0;
    while (sum < N * N) {
        int min = 2147483647;
        int min_idx;
        for (int i = 0; i < N; ++i) {
            if (indexTab[i] < N && t1[i][indexTab[i]] <= min) {
                min = t1[i][indexTab[i]];
                min_idx = i;
            }

        }
        if (min != A[ind - 1]) {
            A[ind] = min;
            ind += 1;
        }
        indexTab[min_idx] += 1;
        sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += indexTab[i];
        }

    }
    printArray(A, ind);
    return 0;
}
