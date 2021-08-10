#include <stdio.h>

#define SIZE 1000


int main() {

    int n;
    int t[SIZE];
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        sum += t[i];
    }


    int s = 0;
    for (int i = 1; i < n; i++) {
        s += t[i - 1];
        if (2 * s == (sum - t[i])) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}

