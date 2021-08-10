#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
    while (k > 0) {
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[max]) { max = i; }
        }
        a[max] = a[max] / 2;
        k -= 1;
    }
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += a[j];
    }
    printf("%d", sum);
    return 0;
}
