#include <stdio.h>


void print(unsigned int length, unsigned int v);


struct tuple {
    unsigned int result, len;
};

struct tuple testt(unsigned int x, unsigned int t, unsigned int res, unsigned int length) {
    struct tuple ressu, temp;
    ressu.result = 0;
    ressu.len = 0;

    if (x == t) {
        ressu.result = res;
        ressu.len = length;
        return ressu;
    } else if (x > t) {
        return ressu;
    }

    unsigned best = 50;

    if (x != 1 && x < 31623) {
        ressu = testt(x * x, t, res, length + 1);
        best = ressu.len;
    }

    temp = testt(2 * x, t, res + (1 << length), length + 1);
    if (best == 0 || (temp.len > 0 && temp.len < best)) {
        ressu = temp;
    }

    return ressu;
}


int main() {
    unsigned int s;
    unsigned int t;

    scanf("%u %u", &s, &t);

    if (t == 1) {
        printf("/");
        return 0;
    }

    if (t == 0) {
        printf("-");
        return 0;
    }

    struct tuple result1, result2;

    result1 = testt(s, t, 0, 0);
    result2 = testt(1, t, 0, 0);

    if (result1.len == 0 && result2.len == 0) {
        printf("NO");
        return 0;
    }
    else if (result2.len == 0) {
        print(result1.len, result1.result);
        return 0;
    }
    else if (result1.len == 0) {
        printf("/");
        print(result2.len, result2.result);
        return 0;
    }
    else if (result1.len <= result2.len + 1) {
        print(result1.len, result1.result);
        return 0;
    }
    else {
        printf("/");
        print(result2.len, result2.result);
        return 0;
    }
}

void print(unsigned int length, unsigned int v) {
    int i;
    unsigned int arr[length];

    for (i = length - 1; i >= 0; --i) {
        if (v >= (1 << i)) {
            arr[i] = 1;
            v -= 1 << i;
        } else {
            arr[i] = 0;
        }
    }

    for (i = 0; i < length; ++i) {
        if (arr[i] == 1) {
            printf("+");
        } else {
            printf("*");
        }
    }
}