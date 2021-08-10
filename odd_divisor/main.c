#include <stdio.h>

long long int f(int x);

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}

long long int f(int x) {
    if (!x) { return 0; }

    long long sum = (x + 1) / 2;
    return sum * sum + f(x / 2);
}