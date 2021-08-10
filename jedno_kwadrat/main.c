#include <stdio.h>
#include <math.h>


int one_square(int i);

int is_prime(int num);

int main() {
    int l, u, k;
    scanf("%d %d %d", &l, &u, &k);
    if (k > u - l + 1) {
        printf("-1");
        return 0;
    }
    int counter = 0;
    for (int i = l; i <= u; ++i) {
        if (is_prime(i)  == 1 && one_square(i)  == 1) {
            counter += 1;
            if ( counter == k) {
                printf("%d", i);
                return 0;
            }
        }

    }
    printf("-1");
    return 0;
}

int is_prime(int num)
{
    if (num <= 1) { return 0; }
    if (num % 2 == 0 && num > 2) { return 0; }
    for(int i = 3; i < (int) sqrt(num) + 1  ; i+= 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int one_square(int i) {

    if (i == 1) { return 1;}
    else if (i == 4) { return 0; }

    int new_i = 0;
    while (i > 0) {
        new_i += (i%10) * (i%10);
        i /= 10;
    }
    return one_square(new_i);
}