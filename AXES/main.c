#include <stdio.h>
#include <math.h>

int num_of_syms(int n, double points[n][2]);


int main() {
    int t;
    scanf("%d", &t);
    int res[t];
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        double arr[n][2];
        for (int j = 0; j < n; ++j) { scanf("%lf %lf", &arr[j][0], &arr[j][1]); }
        res[i] = num_of_syms(n, arr);
    }

    for (int q = 0; q < t; ++q) { printf("%d\n", res[q]); }
    return 0;
}

int num_of_syms(int n, double points[n][2]) {
    double poly[4 * n][2];
    int u = 0;
    for (int i = 0; i < n; ++i) {
        poly[u][0] = points[i][0], poly[u][1] = points[i][1];
        poly[u + 2 * n][0] = points[i][0], poly[u + 2 * n][1] = points[i][1];
        u += 2;
    }
    for (u = 1; u < 4 * n; u += 2) {
        poly[u][0] = (poly[u - 1][0] + poly[u + 1][0]) / 2;
        poly[u][1] = (poly[u - 1][1] + poly[u + 1][1]) / 2;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        double xp = poly[i][0];
        double yp = poly[i][1];
        double xq = poly[i + n][0];
        double yq = poly[i + n][1];
        int is_sym = 1;
        for (int j = 1; j < n; ++j) {
            double xb = poly[i + n - j][0], y_b = poly[i + n - j][1];
            double xa = poly[i + n + j][0], y_a = poly[i + n + j][1];

            double pb = sqrt((xp - xb) * (xp - xb) + (yp - y_b) * (yp - y_b));
            double pa = sqrt((xp - xa) * (xp - xa) + (yp - y_a) * (yp - y_a));

            double qb = sqrt((xq - xb) * (xq - xb) + (yq - y_b) * (yq - y_b));
            double qa = sqrt((xq - xa) * (xq - xa) + (yq - y_a) * (yq - y_a));
            if (qa != qb || pa != pb) {
                is_sym = 0;
                break;
            }
        }
        if (is_sym) { count++; }
    }
    return count;
}
