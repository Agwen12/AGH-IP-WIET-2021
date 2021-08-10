/*
#include <stdio.h>
#include <math.h>

int isPrime(int number) {
    if(number == 2 || number == 3) {
        return 1;
    }
    if (number <= 1 || number % 2 == 0 || number % 3 == 0) {
        return 0;
    }

    int i = 6;
    while ( i*i <= number + 1) {
        if (number % (i - 1) == 0 || number % (i + 1) == 0) {
            return 0;
        }
        i = i + 6;
    }
    return 1;
}


int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    int perfects[100];
    int a = 0;
    //liczby doskonale maja postac 2^(i-1)*(2^p -1), gdzie 2^p - 1 jest liczba pierwsza
    for (int i = 1; i <= log(n)/log(4) + 1; i++) {
        int pr = pow(2,i - 1) * (pow(2, i) - 1);
        if (pr >= m && pr <= pr  && isPrime(pow(2, i) - 1) == 1) {
            perfects[a] = pr;
            a = a + 1;

        }
    }
    printf("%d\n", a);
    for (int i = 0; i < a; i++) {
        printf("%d ", perfects[i]);
    }

    return 0;
}
*/