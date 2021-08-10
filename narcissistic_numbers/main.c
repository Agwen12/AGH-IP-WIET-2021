#include <stdio.h>

int upper_limit(int digits, int base);

int power(int a, int b);

int is_narcissistic(int num, int base, int digits);


int main() {
    int m, b;
    scanf("%d %d", &m, &b);
    int upper = upper_limit(m, b); // biggest m-digit number in base 10
    int lower = power(b, m - 1); // smallest m-digit number in base 10

    int counter = 0;
    for (int i = lower; i <= upper; ++i) { counter += is_narcissistic(i, b, m); }

    if (counter == 0) { printf("NO"); }
    return 0;
}


int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; ++i) { result *= a; }
    return result;
}

int upper_limit(int digits, int base) {
    int upper = 0;
    for (int i = 0; i < digits; ++i) { upper += power(base - 1, digits); }
    return upper;
}

int is_narcissistic(int num, int base, int digits) {
    char b_number[digits + 1];
    int digit;
    int temp = num;
    int result = 0;

    b_number[digits] = '\0';
    for (int i = digits - 1; i > -1; --i) {
        digit = temp % base;
        result += power(digit, digits);
        if (result > num) { return 0; }
        if (digit < 10) {
            b_number[i] = (char) (digit + (int) '0');
        } else {
            b_number[i] = (char) (digit % 10 + (int) 'A');
        }
        temp /= base;
    }

    if (result == num) {
        printf("%s ", b_number);
        return 1;
    }

    return 0;
}
