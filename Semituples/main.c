#include <stdio.h>
#include <stdlib.h>


unsigned long bin2dec(unsigned long *arr, int len) {
    unsigned long result = 0, p2 = 1;
    for (int i = len - 1; i >= 0; --i) {
        if (arr[i] == 1) result += p2;
        p2 *= 2;
    }
    return result;
}

unsigned long *dec2bin(unsigned long *result, unsigned long number, int len) {

    for (int i = 0; i < len; i++) {
        result[i] = number % 2;
        number /= 2;
    }

    for (int i = 0; i < len / 2; i++) {
        unsigned long tmp = result[i];
        result[i] = result[len - 1 - i];
        result[len - 1 - i] = tmp;
    }

    return result;
}


int countSemiTuples(unsigned long number, int n) {

    if (number == 1) return 0;

    unsigned long max_number = 0;
    unsigned long p2 = 1;

    for (int i = 0; i < n; ++i) {
        max_number += p2;
        p2 *= 2;
    }

    unsigned long curr_num = number;
    int counter = 0;
    int checked[max_number + 1];
    for (unsigned long i = 0; i < max_number + 1; ++i) {
        checked[i] = 0;
    }
    while (curr_num <= max_number) {
        unsigned long num_bin[n];
        unsigned long *bin = dec2bin(num_bin, curr_num, n);
        for (int i = 0; i < n; ++i) {
            bin[i] = (bin[i] + 1) % 2;
            unsigned long changed_num = bin2dec(bin, n);
            bin[i] = (bin[i] + 1) % 2;
            if (changed_num % number != 0 && checked[changed_num] == 0) counter++;
            checked[changed_num] = 1;
        }
        curr_num += number;
    }

    return counter;
}


int main() {
    unsigned long num;
    int n;
    scanf("%d %lu", &n, &num);
    int res = countSemiTuples(num, n);
    printf("%d", res);
    return 0;
}