#include <stdio.h>


int max_ternary(int r, int g, int b);

int pelotas(int n, int *red, int *green, int *blue);


int main() {
    int n;
    scanf("%d", &n);
    int red[n], blue[n], green[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &red[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &green[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &blue[i]);
    }
    int result = pelotas(n, red, green, blue);
    printf("%d", result);
    return 0;
}

int max_ternary(int r, int g, int b) {
    int res = r;
    if (g > res) res = g;
    if (b > res) res = b;
    return res;
}

int pelotas(int n, int *red, int *green, int *blue) {
    int swappis[n];
    int color[3];
    for (int q = 0; q < 3; ++q) color[q] = 0;
    int diff_colours = 0;
    for (int i = 0; i < n; ++i) {
        if (red[i] != 0 && color[0] == 0) color[0] = 1, diff_colours++;
        if (red[i] != 0 && color[1] == 0) color[1] = 1, diff_colours++;
        if (red[i] != 0 && color[2] == 0) color[2] = 1, diff_colours++;
        if (diff_colours > n) return -1;
        swappis[i] = red[i] + green[i] + blue[i] - max_ternary(red[i], green[i], blue[i]);
    }
    int swap_todos = 0;
    for (int i = 0; i < n; ++i) swap_todos += swappis[i];
    int result = 10 * swap_todos;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        int curr = swap_todos - swappis[i] - swappis[j] - swappis[k];
                        curr += (green[i] + blue[i]) + (red[j] + blue[j]) + (red[k] + green[k]);
                        if (curr < result) result = curr;
                    }
                }
            }
        }
    }
    return result;
}
