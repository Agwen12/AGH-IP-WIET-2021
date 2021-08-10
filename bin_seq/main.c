#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *A = (int *)calloc((unsigned int)n, sizeof(int));
    int counter = 1;
    int num = 1;
    int temp;
    while ((int)log2((double) num) + 1 <= n && counter < k){
        temp = num;

        for (int i = 0; temp > 0; ++i) {
            A[i] = temp % 2;
            temp /= 2;
        }

        for (int i = 0; i < n - 1; ++i) {
            if ((A[i] & A[i + 1])) {
                break;
            }

            if (i == n - 2) { counter += 1;}
        }

        num += 1;
    }

    if (counter == k) {
        for (int i = n - 1; i > - 1 ; --i) {
            printf("%d", A[i]);
        }
    } else {
        printf("-1");
    }



    return 0;
}