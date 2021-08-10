#include <stdio.h>
#define N 30

int main() {
    int number[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &number[i]);
    }
    for (int i = 0; i < N; ++i) {
        printf("%d", number[i]);
    }
    return 0;
}
