#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    printf("Hello, World!\n");

    int a[] = {2, 1, 3, 4};
    for (int i = 0; i < 4; ++i) {
        printf("%d \n", a[i]);
    }
    qsort(a, sizeof(a)/ sizeof(*a), sizeof(*a), comp);


    for (int i = 0; i < 4; ++i) {
        printf("%d \n", a[i]);
    }
    return 0;
}
