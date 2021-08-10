#include <stdio.h>

#define N 150

int main() {
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);

    int array[q];
    int xors[q][2];
    char temp;
    for (int i = 0; i < q; i++) {
        int j = 0;
        do {
            scanf("%d%c", &xors[i][j], &temp);
            j++;
        } while (temp != '\n' && j < 2);
    }

    int binary[N], binary_ends[N];

    for (int p = 0; p < N; p++) {
        binary[p] = 0;
        binary_ends[p] = 0;
    }

    unsigned char aTab[N], bTab[N];
    scanf("%s", aTab);
    scanf("%s", bTab);


    int h = 0;
    for (int p = n - 1; p > -1; p--) {
        binary[p] = aTab[h] - 48;
        binary_ends[p] = bTab[h] - 48;
        ++h;
    }


    int loop_f = 1, loop_l = 0, counter = 0;
    while (1) {
        for (int i = 0; i < q; i++) {
            array[i] = -1;
        }

        int x = 0;
        while (1) {
            if (loop_f) {
                loop_f = 0;
                break;
            } else {
                binary[x] = (binary[x] + 1) % 2;
                if (binary[x]) {
                    break;
                } else {
                    x++;
                }
            }
        }

        int finish = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == binary_ends[i]) {
                finish++;
            } else {
                break;
            }
        }

        if (finish == n) {
            loop_l = 1;
        }

        while (1) {
            if (array[k - 1] == -1) {
                for (int i = 0; i < q; i++) {
                    if (array[i] == -1) {
                        if (xors[i][0] < 0) {
                            if (xors[i][1] < 0) {
                                if (binary[n + xors[i][0]] == binary[n + xors[i][1]]) {
                                    array[i] = 0;
                                } else {
                                    array[i] = 1;
                                }
                            } else {
                                if (array[xors[i][1] - 1] != -1) {
                                    if (binary[n + xors[i][0]] == array[xors[i][1] - 1]) {
                                        array[i] = 0;
                                    } else {
                                        array[i] = 1;
                                    }
                                } else {
                                    continue;
                                }
                            }
                        } else {
                            if (array[xors[i][0] - 1] != -1) {
                                if (xors[i][1] < 0) {

                                    if (array[xors[i][0] - 1] == binary[n + xors[i][1]]) {
                                        array[i] = 0;
                                    } else {
                                        array[i] = 1;
                                    }
                                } else {
                                    if (array[xors[i][1] - 1] != -1) {
                                        int f = array[xors[i][0] - 1];
                                        int s = array[xors[i][1] - 1];
                                        if (f == s) {
                                            array[i] = 0;
                                        } else {
                                            array[i] = 1;
                                        }
                                    } else {
                                        continue;
                                    }
                                }
                            } else {
                                continue;
                            }
                        }
                    } else {
                        continue;
                    }
                }

            } else {
                if (array[k - 1]) {
                    counter++;
                    break;
                } else {
                    break;
                }
            }
        }

        if (loop_l) {
            break;
        }
    }


    printf("%d", counter);
    return 0;
}