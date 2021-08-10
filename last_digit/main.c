#include <stdio.h>

long long int get_div(int x);
long long int power(int a, int b);
int count_digits(long long int a);

int main() {
    long long int s, result;
    scanf("%lli", &s);
    result = 0;


    int digits = count_digits(s);
    long long int div = get_div(digits);
    long long int s2 = s;
    while (div > 0) {
        result += power(1, digits) * (s / div);
        s %= div;
        div /= 10;
        digits -= 1;
    }

    long long int result2 = result;
    s = 0;
    while (result2 > 0) {
        s += result2;
        result2 /= 10;
    }

    if (s == s2) {
        printf("%lli", result);
    } else {
        printf("-1");
    }
    return 0;
}

int count_digits(long long int a) {
    int dig = 0;
    while (a > 0) {
        dig += 1;
        a /= 10;
    }
    return dig;
}

long long int power(int a, int b) {
    long long int res = a;
    for (int i = 0; i < b - 1; ++i) {
        res *= 10;
    }
    return res;
}

long long get_div(int x) {
    long long div = 0;
    for (int i = 0; i < x; ++i) {
        div = div * 10 + 1;
    }

    return div;
}

