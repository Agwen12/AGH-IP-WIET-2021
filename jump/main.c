#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n, length;
    unsigned int finish = 0;
    scanf("%u", &n);


    unsigned int *array1 = calloc(n, sizeof(unsigned int));
    unsigned long *array2 = calloc(n, sizeof(unsigned long));

    for (int i = 0; i < n; ++i) {
        scanf("%u %lu", &array1[i], &array2[i]);
    }

    length = array1[n - 1] + 101;
    unsigned long *cells = calloc(length, sizeof(unsigned long));

    for (int i = 0; i < n; ++i) {
        cells[array1[i] + 50] = array2[i];
    }

    while (finish == 0) {
        finish = 1;
        for (int i = 0; i < length; ++i) {
            if (cells[i] >= 3) {
                cells[i - 2] += cells[i] / 3;
                cells[i + 2] += cells[i] / 3;
                cells[i] %= 3;
                finish = 0;
            }
        }
    }

    int pos = length - 2;
    while (1) {
        if (pos <= 2) {
            break;
        } if (cells[pos] > 0 && cells[pos + 1] > 0) {
            cells[pos] -= 1;
            cells[pos + 2] += 1;
            cells[pos + 1] -= 1;
            pos += 2;
        } else if (cells[pos] == 2 && cells[pos - 1] > 0) {
            pos -= 1;
        } else if (cells[pos] == 2 && cells[pos + 1] == 0) {
            cells[pos] = 0;
            cells[pos + 1] += 1;
            cells[pos - 2] += 1;
            pos += 1;
        } else if (cells[pos] == 3) {
            cells[pos - 2] += 1;
            cells[pos + 2] += 1;
            cells[pos] = 0;
            pos += 2;
        } else {
            pos -= 1;
            while (cells[pos] == 0) {
                pos -= 1;
                if (pos <= 2) {
                    break;
                }
            }
        }
    }

    for (pos = 0; pos < length; ++pos) {
        if (cells[pos] == 1) {
            printf("%d ", pos - 50);
        }
    }

    free(cells);
    free(array1);
    free(array2);


    return 0;
}