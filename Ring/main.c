#include <stdio.h>
#define N 50

int is_prime(int number) {
    if (number <= 3 && number > 1)
        return 1;            // as 2 and 3 are prime
    else if (number % 2 == 0 || number % 3 == 0)
        return 0;     // check if number is divisible by 2 or 3
    else {
        unsigned int i;
        for (i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0)
                return 0;
        }
        return 1;
    }
}

int main() {
    char s[N];
    int n = 0;
    scanf("%s", s);
    while (s[n] != '\0') {
        n++;
    }
    char result[N];
    int oo[N];
    int idx = 0;
    char min = s[0];
    // finds minimal char
    for (int i = 0; i < n; ++i) {
        if (s[i] < min) { min = s[i]; }
//        result[i] = s[i];
    }
    for (int i = 0; i < n; ++i) {
        result[i] = 'z';
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == min) {
            oo[idx] = i;
            idx++;
        }
    }
    if (idx == n) {
        printf("%s", s);
        return 0;
    }

    for (int i = 0; i < idx; ++i) {
        int o = oo[i];
        for (int j = 2; j < n; ++j) {
            if (is_prime(j)) {
                char helper[N];
                int index = o;
//                helper[0] = s[index];
                for (int k = 0; k < n; ++k) {
                    helper[k] = s[(index + j*k) % n];
                }
                int y = 0;
                while (1) {
                    if (helper[y] == result[y]) {
                        y++;
                        if (y >= n) break;
                    } else if (result[y] < helper[y]) {
                        break;
                    } else {
                        for (int k = 0; k < n; ++k) { // ressult[y] > helper[y]
                            result[k] = helper[k];
                        }
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%c", result[i]);
    }


    return 0;
}
